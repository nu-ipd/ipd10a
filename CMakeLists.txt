# Configuration for building example C programs.
cmake_minimum_required(VERSION 3.10)
project(ipd10a C)
include(.ipd/cmake/CMakeLists.txt)

add_c_program(sort src/sort)
add_c_program(array_fun src/array_fun.c)

add_c_program(visible_strings src/visible_strings.c)
add_c_program(visible_chars src/visible_chars.c)

add_c_program(sort_refactored src/sort_refactored.c)
add_c_program(sort_on_stack src/sort_on_stack.c)
add_c_program(sort_structs_on_stack src/sort_structs_on_stack.c)
add_c_program(sort_ptrs_on_stack src/sort_ptrs_on_stack.c)

add_c_test_program(ipd10a-3 exercise/ipd10a-3.c)
add_c_test_program(ipd10a-4 exercise/ipd10a-4.c)
add_c_test_program(ipd10a-5 exercise/ipd10a-5.c)
