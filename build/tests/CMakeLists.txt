cmake_minimum_required(VERSION 3.10)

project(Calculator CLI)

set(CMAKE_CXX_STANDARD 11)

# Add GoogleTest submodule if it's not already in the project
add_subdirectory(googletest)

# Include directories for headers
include_directories(include)

# Add the source files for your project
add_executable(calculator
    src/main.cpp
    src/calculator.cpp
    src/parser.cpp
)

# Link GoogleTest to your project
enable_testing()
add_executable(test_calculator
    tests/test_calculator.cpp
)

target_link_libraries(test_calculator gtest gtest_main)

add_test(NAME TestCalculator COMMAND test_calculator)
