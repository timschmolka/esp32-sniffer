# The following five lines of boilerplate have to be in your project's
# CMakeLists in this exact order for cmake to work correctly
cmake_minimum_required(VERSION 3.16)
add_compile_definitions(WIFI_CHANNEL=${WIFI_CHANNEL})
include($ENV{IDF_PATH}/tools/cmake/project.cmake)
project(puppy-esp-sniffer)
