#ifndef TERMINAL_UI_HH_
#define TERMINAL_UI_HH_

#include <cstdint>
#include <string>
#include <unordered_map>
#include <vector>

#define GREEN "\033[0;32m"
#define RED "\033[0;31m"
#define YELLOW "\033[0;33m"

#define RESET "\033[0m"


void display_array(std::vector<uint16_t> arr,
                   std::unordered_map<uint16_t, std::string> color_map);


void display_finished(std::vector<uint16_t> arr);


#endif
