#include "sort/sort.hpp"

#include <algorithm>
#include <random>

#include "external_test_framework/utest.h"


#define VECTOR_SIZE 1000
#define MINVAL      0
#define MAXVAL      10000


/** @brief Helper function to generate a vector with random numbers. */
static std::vector<uint16_t> generate_vector_with_rand_nums() {
    std::vector<uint16_t> v;
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(MINVAL, MAXVAL);

    for (uint16_t i = 0; i < VECTOR_SIZE; i++) {
        uint16_t randnum = dis(gen);
        v.push_back(randnum);
    }
    return v;
}


/** @brief Helper function to return a sorted version of a given vector. */
static std::vector<uint16_t> sort_vector(std::vector<uint16_t> v) {
    std::vector<uint16_t> sorted_v(v);
    std::sort(sorted_v.begin(), sorted_v.end());
    return sorted_v;
}


void display_mock(std::vector<uint16_t> arr,
                  std::unordered_map<uint16_t, std::string> color_map) {
    static_cast<void>(arr);
    static_cast<void>(color_map);
}


UTEST(test_sort, test_bubble_sort) {
    // Generate a vector with random values
    std::vector<uint16_t> v = generate_vector_with_rand_nums();

    // Generate a sorted version of the random vector
    std::vector<uint16_t> sorted_v = sort_vector(v);

    // Sort the random vector with the bubble sort function
    bubble_sort(v, display_mock);
    // Make sure the bubble sort function works and the vector is sorted
    for (uint16_t i = 0; i < VECTOR_SIZE; i++) {
        ASSERT_EQ(v[i], sorted_v[i]);
    }
}

UTEST(test_sort, test_selection_sort) {
    // Generate a vector with random values
    std::vector<uint16_t> v = generate_vector_with_rand_nums();

    // Generate a sorted version of the random vector
    std::vector<uint16_t> sorted_v = sort_vector(v);

    // Sort the random vector with the bubble sort function
    selection_sort(v, display_mock);
    // Make sure the bubble sort function works and the vector is sorted
    for (uint16_t i = 0; i < VECTOR_SIZE; i++) {
        ASSERT_EQ(v[i], sorted_v[i]);
    }
}

UTEST(test_sort, test_insertion_sort) {
    // Generate a vector with random values
    std::vector<uint16_t> v = generate_vector_with_rand_nums();

    // Generate a sorted version of the random vector
    std::vector<uint16_t> sorted_v = sort_vector(v);

    // Sort the random vector with the bubble sort function
    insertion_sort(v, display_mock);
    // Make sure the bubble sort function works and the vector is sorted
    for (uint16_t i = 0; i < VECTOR_SIZE; i++) {
        ASSERT_EQ(v[i], sorted_v[i]);
    }
}

UTEST(test_sort, test_merge_sort) {
    // Generate a vector with random values
    std::vector<uint16_t> v = generate_vector_with_rand_nums();

    // Generate a sorted version of the random vector
    std::vector<uint16_t> sorted_v = sort_vector(v);

    // Sort the random vector with the bubble sort function
    merge_sort(v, display_mock);
    // Make sure the bubble sort function works and the vector is sorted
    for (uint16_t i = 0; i < VECTOR_SIZE; i++) {
        ASSERT_EQ(v[i], sorted_v[i]);
    }
}

UTEST(test_sort, test_quick_sort) {
    // Generate a vector with random values
    std::vector<uint16_t> v = generate_vector_with_rand_nums();

    // Generate a sorted version of the random vector
    std::vector<uint16_t> sorted_v = sort_vector(v);

    // Sort the random vector with the bubble sort function
    quick_sort(v);
    // Make sure the bubble sort function works and the vector is sorted
    for (uint16_t i = 0; i < VECTOR_SIZE; i++) {
        ASSERT_EQ(v[i], sorted_v[i]);
    }
}

UTEST(test_sort, test_heap_sort) {
    // Generate a vector with random values
    std::vector<uint16_t> v = generate_vector_with_rand_nums();

    // Generate a sorted version of the random vector
    std::vector<uint16_t> sorted_v = sort_vector(v);

    // Sort the random vector with the bubble sort function
    heap_sort(v);
    // Make sure the bubble sort function works and the vector is sorted
    for (uint16_t i = 0; i < VECTOR_SIZE; i++) {
        ASSERT_EQ(v[i], sorted_v[i]);
    }
}

UTEST_MAIN();
