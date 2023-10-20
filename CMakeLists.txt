cmake_minimum_required(VERSION 3.12)

project(HelloWorld)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

option(ENABLE_TESTING "Enable testing" ON)

if (ENABLE_TESTING)
    include(CTest)

    add_subdirectory(test)

    enable_testing()

    # Внесите изменения для скачивания и настройки Google Test
    include(FetchContent)
    FetchContent_Declare(googletest
        URL https://github.com/google/googletest/archive/refs/tags/release-1.11.0.zip
    )

    set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

    FetchContent_MakeAvailable(googletest)
endif()

add_library(my_functions src/fun.cpp)

target_include_directories(my_functions PUBLIC include)

add_executable(hello_world src/hello-world.cpp)

target_link_libraries(hello_world my_functions)

# Убедитесь, что вы также включили библиотеку Google Test в ваш тестовый исполняемый файл
add_executable(test_hello_world test/test_fun.cpp)

target_link_libraries(test_hello_world gtest gtest_main my_functions)

add_test(NAME test_hello_world COMMAND test_hello_world)
