#include "sort.hpp"

#include <algorithm>
#include <iostream>

#include "../terminal_ui/terminal_ui.hpp"

#define ARR_LEN arr.size()


// BUBBLE SORT
void bubble_sort(std::vector<uint16_t>& arr,
                 std::function<void(std::vector<uint16_t>,
                                    std::unordered_map<uint16_t, std::string>)> display) {
    bool swapped;

    for (int i = 0; i < ARR_LEN -1; i++) {
        swapped = false;

        // Compare and swap elements if needed.
        for (int j = 0; j < ARR_LEN - i -1; j ++) {
            if (arr[j] > arr[j + 1]) {
                std::swap(arr[j], arr[j + 1]);
                swapped = true;

                // Highlight the swapped indices with different color
                std::unordered_map<uint16_t, std::string> color_map {
                    {j, RED}, {j + 1, GREEN}
                };
                display(arr, color_map);
            }
        }

        // If not swapping, the array is sorted.
        if(!swapped) {
            break;
        }
    }
    display_finished(arr);
}


// SELECTION SORT
void selection_sort(std::vector<uint16_t>& arr,
                    std::function<void(std::vector<uint16_t>,
                                       std::unordered_map<uint16_t, std::string>)> display) {

    for (int i = 0; i < ARR_LEN; i++) {
        // Set current index as min.
        int min = i;

        for (int j = i + 1; j < ARR_LEN; j++) {
            // Interate through the rest of the array.
            // Update min index if smaller element found.
            if (arr[j] < arr[min]) {
                min = j;
            }
        }

        // Swap the current element with the min index found.
        std::swap(arr[i], arr[min]);
        // Highlight the swapped indices with different color
        std::unordered_map<uint16_t, std::string> color_map {
            {i, RED}, {min, GREEN}
        };
        display(arr, color_map);
    }

    display_finished(arr);
}


// INSERTION SORT
void insertion_sort(std::vector<uint16_t>& arr,
                    std::function<void(std::vector<uint16_t>,
                                       std::unordered_map<uint16_t, std::string>)> display) {
    for (int i = 1; i < ARR_LEN; i++){
        // Key start at the second element.
        int key = arr[i];
        int j = i - 1;

        // While left element smaller than the key:
        // Push it to the left 
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            arr[j] = key;
            j--;
            std::unordered_map<uint16_t, std::string> color_map {
                {j + 1, RED}, {j, GREEN}, {i, YELLOW}
            };
            display(arr, color_map);
        }
        // Swap the left element with the key since key smaller.
        arr[j + 1] = key;
    }

    display_finished(arr);
}


void merge_sort(std::vector<uint16_t>& arr,
                std::function<void(std::vector<uint16_t>,
                                   std::unordered_map<uint16_t, std::string>)> display) {

    if (ARR_LEN <= 1 ) {
        return;
    }

    std::unordered_map<uint16_t, std::string> color_map{};

    // Split the array into two halves.
    int mid = ARR_LEN / 2;
    std::vector<uint16_t> subleft(arr.begin(), arr.begin() + mid);
    std::vector<uint16_t> subright(arr.begin() + mid, arr.end());

    // Recursively sort the left and right subarrays.
    merge_sort(subleft, display);
    merge_sort(subright, display);

    // Merge the sorted subarrays back into the original array.
    int left = 0, right = 0, i = 0;

    while (left < subleft.size() && right < subright.size()) {
        if (subleft[left] < subright[right]) {
            arr[i++] = subleft[left++];
        } else {
            arr[i++] = subright[right++];
        }
        display_array(arr, color_map);
    }

    // Add any remaining elements from the left subarray.
    while (left < subleft.size()) {
        arr[i++] = subleft[left++];
        display_array(arr, color_map);
    }

    // Add any remaining elements from the right subarray.
    while (right < subright.size()) {
        arr[i++] = subright[right++];
        display_array(arr, color_map);
    }
}


void quick_sort(std::vector<uint16_t>& arr) {
    std::sort(arr.begin(), arr.end()); // TODO: remove this and actually implement the algo.
}

void heap_sort(std::vector<uint16_t>& arr) {
    std::sort(arr.begin(), arr.end()); // TODO: remove this and actually implement the algo.
}
