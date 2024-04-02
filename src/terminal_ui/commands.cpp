#include "commands.hpp"

#include <algorithm>
#include <iostream>
#include <random>
#include <vector>

#include "../sort/sort.hpp"
#include "sorting_ui.hpp"

#define ARR_SIZE 30

void print_help()
{
    std::cout << " These are algorithm this visualizer support: \n";
    std::cout << "\t bubble_sort       Bubble Sort visualizer\n";
    std::cout << "\t merge_sort        Bubble Sort visualizer\n";
    std::cout << "\t insertion sort    Bubble Sort visualizer\n";
    std::cout << "\t selection_sort    Bubble Sort visualizer\n";
    std::cout << "\t quick_sort        Quick Sort visualizer\n";
    std::cout << "\t heap sort         Heap Sort visualizer\n";
    std::cout << "\t quit              Close the program\n";
}

void quit()
{
    exit(0);
}

std::vector<uint16_t> generate_array()
{
    std::vector<uint16_t> arr;
    for (int i = 1; i <= ARR_SIZE; i++)
    {
        arr.push_back(i);
    }

    std::shuffle(arr.begin(), arr.end(), std::random_device());
    return arr;
}

void visualize_bubble_sort()
{
    std::vector<uint16_t> arr = generate_array();
    bubble_sort(arr, &display_array, &display_finished);
}

void visualize_merge_sort()
{
    std::vector<uint16_t> arr = generate_array();
    merge_sort(arr, &display_array, &display_finished);
}

void visualize_insertion_sort()
{
    std::vector<uint16_t> arr = generate_array();
    insertion_sort(arr, &display_array, display_finished);
}

void visualize_selection_sort()
{
    std::vector<uint16_t> arr = generate_array();
    selection_sort(arr, &display_array, display_finished);
}

void visualize_quick_sort()
{
    std::vector<uint16_t> arr = generate_array();
    quick_sort(arr, &display_array, display_finished);
}

void visualize_heap_sort()
{
    std::vector<uint16_t> arr = generate_array();
    heap_sort(arr, &display_array, display_finished);
}
