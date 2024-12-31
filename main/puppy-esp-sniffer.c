#include <stdio.h>
#include "esp_system.h"
#include "esp_wifi.h"
#include "esp_event.h"
#include "nvs_flash.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_task_wdt.h"
#include "sdkconfig.h"

static volatile int packet_count = 0;

void init_nvs() {
    esp_err_t ret = nvs_flash_init();
    if (ret == ESP_ERR_NVS_NO_FREE_PAGES || ret == ESP_ERR_NVS_NEW_VERSION_FOUND) {
        ESP_ERROR_CHECK(nvs_flash_erase());
        ret = nvs_flash_init();
    }
    ESP_ERROR_CHECK(ret);
}

void wifi_sniffer_packet_handler(void *buf, wifi_promiscuous_pkt_type_t type) {
    packet_count++;
}

void init_wifi_sniffer() {
    wifi_init_config_t cfg = WIFI_INIT_CONFIG_DEFAULT();
    ESP_ERROR_CHECK(esp_wifi_init(&cfg));
    ESP_ERROR_CHECK(esp_wifi_set_mode(WIFI_MODE_NULL));
    ESP_ERROR_CHECK(esp_wifi_set_promiscuous(true));
    ESP_ERROR_CHECK(esp_wifi_set_channel(CONFIG_WIFI_CHANNEL, WIFI_SECOND_CHAN_NONE));
    ESP_ERROR_CHECK(esp_wifi_set_promiscuous_rx_cb(wifi_sniffer_packet_handler));
    ESP_ERROR_CHECK(esp_wifi_start());
    printf("Sniffer is running on channel %d\n", CONFIG_WIFI_CHANNEL);
}

void pps_task(void *param) {
    while (1) {
        printf("Packets per second: %d\n", packet_count);
        packet_count = 0;
        vTaskDelay(pdMS_TO_TICKS(1000));
    }
}

void app_main(void) {
    ESP_ERROR_CHECK(esp_event_loop_create_default());
    init_nvs();
    init_wifi_sniffer();

    // Create the PPS task
    xTaskCreate(pps_task, "PPS Task", 2048, NULL, 5, NULL);

    printf("Sniffer is running in monitor mode. Capturing packets...\n");

    // Main loop
    while (1) {
        vTaskDelay(pdMS_TO_TICKS(500)); // Keep the task alive
    }
}
