#include "terminal_ui.hpp"

#include <iostream>
#include <unistd.h>

// Constants for sleep durations in microseconds
#define SHORT_SLEEP_DURATION 30000  // Short sleep time for faster display updates
#define LONG_SLEEP_DURATION  200000 // Long sleep time for slower display updates


void display_array(std::vector<uint16_t> arr,
                   std::unordered_map<uint16_t, std::string> color_map,
                   uint32_t sleep_time) {

    system("clear");

    // Display array as bars graph
    for (int i = 0; i < arr.size(); i++) {
        // Change bar and text color based on the color map from sorting algorithm
        if (color_map.find(i) != color_map.end()) {
            std::cout << color_map[i];
        }
        std::cout << "   " << arr[i] << "\t";
        for (int j = 0; j < arr[i]; j++){
            std::cout << "██";
        }
        // Switch back to original text color
        std::cout << RESET;
        std::cout << std::endl;
    }
    // Introduce a delay to control the display speed
    usleep(sleep_time);
}


void display_array(std::vector<uint16_t> arr,
                   std::unordered_map<uint16_t, std::string> color_map) {
    display_array(arr, color_map, LONG_SLEEP_DURATION);
}


void display_finished(std::vector<uint16_t> arr) {
    for (int i = 0; i <= arr.size(); i++) {
        std::unordered_map<uint16_t, std::string> color_map;
        for (uint16_t j = 0; j < i; j++) {
            color_map[j] = GREEN;
        }
        display_array(arr, color_map, SHORT_SLEEP_DURATION);
    }
}
