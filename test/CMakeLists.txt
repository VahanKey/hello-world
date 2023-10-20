cmake_minimum_required(VERSION 3.12)

project(HelloWorldTests)

add_executable(test_hello_world test_fun.cpp)

# Укажите, что тестовое приложение зависит от библиотеки Google Test
target_link_libraries(test_hello_world gtest gtest_main my_functions)

add_test(NAME test_hello_world COMMAND test_hello_world)