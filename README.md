# Puppy ESP Sniffer

Puppy ESP Sniffer is a Wi-Fi packet sniffer built for ESP32 devices using the ESP-IDF framework. This project allows you to capture and monitor Wi-Fi packets in promiscuous mode, making it useful for learning about wireless communication or debugging network issues.

## Features

- Captures Wi-Fi packets in promiscuous mode.
- Displays packets-per-second (PPS) statistics.
- Configurable Wi-Fi channel selection.

## Requirements

- ESP32 development board.
- [ESP-IDF](https://github.com/espressif/esp-idf) version 5.5.0 or later.
- A computer with `idf.py` and Python installed.

## Configuration

You can configure the Wi-Fi channel through the `menuconfig` interface:

```bash
idf.py menuconfig
```

Navigate to `Sniffer Configuration` to set the desired Wi-Fi channel.

## Installation

1. Clone the repository:
   ```bash
   git clone <repository-url>
   cd puppy-esp-sniffer
   ```

2. Initialize the ESP-IDF environment:
   ```bash
   . $IDF_PATH/export.sh
   ```

3. Build the project:
   ```bash
   idf.py build
   ```

4. Flash the firmware to your ESP32 device:
   ```bash
   idf.py flash
   ```

5. Monitor the serial output:
   ```bash
   idf.py monitor
   ```

## Usage

Once flashed, the ESP32 will start capturing Wi-Fi packets and output the number of packets captured per second. You can view this information via the serial monitor.

## Project Structure

```
puppy-esp-sniffer/
├── CMakeLists.txt      # Project build configuration
├── main/
│   ├── Kconfig         # Component configuration
│   ├── puppy-esp-sniffer.c  # Main sniffer logic
│   ├── CMakeLists.txt  # Component build configuration
├── sdkconfig           # SDK configuration (auto-generated)
└── README.md           # This file
```

## License

This project is licensed under the [MIT License](LICENSE). Please provide appropriate credit if you use this code.

## Contributions

Contributions are welcome! Feel free to open issues or submit pull requests.

## Disclaimer

This tool is intended for educational and debugging purposes only. Ensure you comply with your local regulations regarding Wi-Fi monitoring.
