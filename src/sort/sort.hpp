#ifndef SORTING_HPP_
#define SORTING_HPP_

#include <cstdint>
#include <functional>
#include <string>
#include <unordered_map>
#include <vector>


void bubble_sort(std::vector<uint16_t>& arr, 
                 std::function<void(std::vector<uint16_t>,
                                    std::unordered_map<uint16_t, std::string>)> display,
                 std::function<void(std::vector<uint16_t>)> final_display);

void selection_sort(std::vector<uint16_t>& arr,
                    std::function<void(std::vector<uint16_t>,
                                       std::unordered_map<uint16_t, std::string>)> display,
                    std::function<void(std::vector<uint16_t>)> final_display);

void insertion_sort(std::vector<uint16_t>& arr,
                    std::function<void(std::vector<uint16_t>,
                                       std::unordered_map<uint16_t, std::string>)> display,
                    std::function<void(std::vector<uint16_t>)> final_display);

void merge_sort(std::vector<uint16_t>& arr,
                std::function<void(std::vector<uint16_t>,
                                   std::unordered_map<uint16_t, std::string>)> display,
                std::function<void(std::vector<uint16_t>)> final_display);

void quick_sort(std::vector<uint16_t>& arr,
                std::function<void(std::vector<uint16_t>,
                                   std::unordered_map<uint16_t, std::string>)> display,
                std::function<void(std::vector<uint16_t>)> final_display);

void heap_sort(std::vector<uint16_t>& arr);

#endif
