#ifndef SORTING_HH_
#define SORTING_HH_

#include <cstdint>
#include <functional>
#include <string>
#include <unordered_map>
#include <vector>


void bubble_sort(std::vector<uint16_t>& arr, 
                 std::function<void(std::vector<uint16_t>,
                                    std::unordered_map<uint16_t, std::string>)> display);

void selection_sort(std::vector<uint16_t>& arr,
                    std::function<void(std::vector<uint16_t>,
                                       std::unordered_map<uint16_t, std::string>)> display);

void insertion_sort(std::vector<uint16_t>& arr,
                    std::function<void(std::vector<uint16_t>,
                                       std::unordered_map<uint16_t, std::string>)> display);

void merge_sort(std::vector<uint16_t>& arr,
                std::function<void(std::vector<uint16_t>,
                                   std::unordered_map<uint16_t, std::string>)> display);

void quick_sort(std::vector<uint16_t>& arr);

void heap_sort(std::vector<uint16_t>& arr);

#endif
