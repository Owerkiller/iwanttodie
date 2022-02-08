cmake_minimum_required(VERSION 3.20)
project(_course_ C)

set(CMAKE_C_STANDARD 11)

add_executable(_course_ main.c libs/algorithms/array/array.c libs/algorithms/array/array.h libs/data_structures/vector/vector.c libs/data_structures/vector/vector.h)

add_subdirectory(libs)
target_link_libraries(_course_ data_structures)
target_link_libraries(_course_ algorithms)
