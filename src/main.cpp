#include <iostream>
#include <algorithm>
#include <random>

#include "sort/sort.hpp"
#include "terminal_ui/terminal_ui.hpp"

#define ARR_SIZE 20

std::vector<uint16_t> generate_array() {
    std::vector<uint16_t> arr;
    for (int i = 1; i <= ARR_SIZE; i++) {
        arr.push_back(i);
    }

    std::shuffle(arr.begin(), arr.end(), std::random_device());
    return arr;
}

int main() {

    std::vector<uint16_t> arr = generate_array();
    //bubble_sort(arr, &display_array);
    //selection_sort(arr, &display_array);
    insertion_sort(arr, &display_array);
    //merge_sort(arr, &display_array);
    return 0;
}
