add_library(Sort
            sort/sort.hpp sort/sort.cpp
            terminal_ui/sorting_ui.cpp
            terminal_ui/commands.cpp)
add_executable(Main main.cpp)
target_link_libraries(Main Sort)
