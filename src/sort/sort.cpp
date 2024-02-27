#include "sort.hpp"

#include <algorithm>
#include <iostream>

#include "../terminal_ui/sorting_ui.hpp"

#define ARR_LEN arr.size()


void bubble_sort(std::vector<uint16_t>& arr,
                 std::function<void(std::vector<uint16_t>,
                                    std::unordered_map<uint16_t, std::string>)> display,
                 std::function<void(std::vector<uint16_t>)> final_display) {
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
    final_display(arr);
}


void selection_sort(std::vector<uint16_t>& arr,
                    std::function<void(std::vector<uint16_t>,
                                       std::unordered_map<uint16_t, std::string>)> display,
                    std::function<void(std::vector<uint16_t>)> final_display) {

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

    final_display(arr);
}


void insertion_sort(std::vector<uint16_t>& arr,
                    std::function<void(std::vector<uint16_t>,
                                       std::unordered_map<uint16_t, std::string>)> display,
                    std::function<void(std::vector<uint16_t>)> final_display) {
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

    final_display(arr);
}


void merge_sort(std::vector<uint16_t>& arr,
                uint16_t left_idx,
                uint16_t right_idx,
                std::function<void(std::vector<uint16_t>,
                                   std::unordered_map<uint16_t, std::string>)> display) {
    if (left_idx == right_idx) {
        return;
    }

    // Split the array into two halves.
    int mid = (left_idx + right_idx) / 2;

    // Recursively sort the left and right subarrays.
    merge_sort(arr, left_idx, mid, display);
    merge_sort(arr, mid + 1, right_idx, display);

    // Merge the sorted subarrays back into the original array.
    int left = left_idx, right = mid + 1, i = 0;
    std::vector<uint16_t> tmp(right_idx - left_idx + 1, 0);

    while (left <= mid && right <= right_idx) {
        if (arr[left] < arr[right]) {
            tmp[i++] = arr[left++];
        } else {
            tmp[i++] = arr[right++];
        }
        std::unordered_map<uint16_t, std::string> color_map {
            {left, RED}, {right,YELLOW}};
        display(arr, color_map);
    }

    // Add any remaining elements from the left subarray.
    while (left <= mid) {
        tmp[i++] = arr[left++];
        std::unordered_map<uint16_t, std::string> color_map {
            {left, RED}, {right,YELLOW}};
        display(arr, color_map);
    }

    // Add any remaining elements from the right subarray.
    while (right <= right_idx) {
        tmp[i++] = arr[right++];
        std::unordered_map<uint16_t, std::string> color_map {
            {left, RED}, {right, YELLOW}};
        display(arr, color_map);
    }

    // Copy tmp arr back into the original array
    left = left_idx;
    for (int i = 0; i < tmp.size(); i++) {
        arr[left++] = tmp[i];
        std::unordered_map<uint16_t, std::string> color_map {
            {left, GREEN}};
        display(arr, color_map);
    }
}


void merge_sort(std::vector<uint16_t>& arr,
                std::function<void(std::vector<uint16_t>,
                                   std::unordered_map<uint16_t, std::string>)> display,
                std::function<void(std::vector<uint16_t>)> final_display) {
    merge_sort(arr, 0, arr.size() - 1, display);
    final_display(arr);
}


void quick_sort(std::vector<uint16_t>& arr, 
                int start_idx,
                int end_idx,
                std::function<void(std::vector<uint16_t>,
                                   std::unordered_map<uint16_t, std::string>)> display) {
    if (start_idx < end_idx) {
        uint16_t pivot = arr[(start_idx + end_idx) / 2];
        int left_ptr = start_idx;
        int right_ptr = end_idx;

        std::unordered_map<uint16_t, std::string> color_map {
            {start_idx, YELLOW}, {end_idx, YELLOW}, {pivot, GREEN}};
        display(arr, color_map);

        while (left_ptr <= right_ptr) {
            // Move left pointer to the right until a value smaller than the pivot is found
            while (arr[left_ptr] < pivot) {
                left_ptr++;
                std::unordered_map<uint16_t, std::string> color_map {
                    {start_idx, YELLOW}, {end_idx, YELLOW}, {left_ptr, RED}, 
                    {right_ptr, RED}, {pivot, GREEN}};
                display(arr, color_map);
            }
            // Move right pointer to the left until a value greater than the pivot is found
            while (arr[right_ptr] > pivot) {
                right_ptr--;
                std::unordered_map<uint16_t, std::string> color_map {
                    {start_idx, YELLOW}, {end_idx, YELLOW}, {left_ptr, RED}, 
                    {right_ptr, RED}, {pivot, GREEN}};
                display(arr, color_map);
            }
            // Swap elements at left_ptr and right_ptr if they are out of order
            if (left_ptr <= right_ptr) {
                std::swap(arr[left_ptr++], arr[right_ptr--]);
                std::unordered_map<uint16_t, std::string> color_map {
                    {start_idx, YELLOW}, {end_idx, YELLOW}, {left_ptr, RED}, 
                    {right_ptr, RED}, {pivot, GREEN}};
                display(arr, color_map);
            }
        }
        quick_sort(arr, start_idx, right_ptr, display);
        quick_sort(arr, left_ptr, end_idx, display);
    }
}

void quick_sort(std::vector<uint16_t>& arr,
                std::function<void(std::vector<uint16_t>,
                                   std::unordered_map<uint16_t, std::string>)> display,
                std::function<void(std::vector<uint16_t>)> final_display) {
    quick_sort(arr, 0, arr.size() - 1, display);
    final_display(arr);
}

void heap_sort(std::vector<uint16_t>& arr) {
    std::sort(arr.begin(), arr.end()); // TODO: remove this and actually implement the algo.
}
