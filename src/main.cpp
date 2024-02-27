#include <iostream>

#include "sort/sort.hpp"
#include "terminal_ui/commands.hpp"
#include "terminal_ui/sorting_ui.hpp"


int main() {
    std::cout << " _   _  _                     _   _____               _   " << std::endl;
    std::cout << "| | | |(_)                   | | /  ___|             | |  " << std::endl;
    std::cout << "| | | | _  ___  _   _   __ _ | | \\ `--.   ___   _ __ | |_ " << std::endl;
    std::cout << "| | | || |/ __|| | | | / _` || |  `--. \\ / _ \\ | '__|| __|" << std::endl;
    std::cout << "\\ \\_/ /| |\\__ \\| |_| || (_| || | /\\__/ /| (_) || |   | |_ " << std::endl;
    std::cout << " \\___/ |_||___/ \\__,_| \\__,_||_| \\____/  \\___/ |_|    \\__|" << std::endl;
    std::cout << std::endl;

    print_help();

    while (true) {
        // Take user input
        std::string user_input;
        std::cout << "> ";
        std::cin >> user_input;

        if (user_input == "help") {
            print_help();
        } else if (user_input == "q" || user_input == "quit") {
            quit();
        } else if (user_input == "bubble_sort" || user_input == "bubble") {
            visualize_bubble_sort();
        } else if (user_input == "insertion_sort" || user_input == "insertion") {
            visualize_insertion_sort();
        } else if (user_input == "merge_sort" || user_input == "merge") {
            visualize_merge_sort();
        } else if (user_input == "selection_sort" || user_input == "selection") {
            visualize_selection_sort();
        } else if (user_input == "quick_sort" || user_input == "quick") {
            visualize_quick_sort();
        } else {
            std::cout << RED << "Invalid input" << RESET << std::endl;
        }
    }

    return 0;
}
