cmake_minimum_required(VERSION 3.5)

project(MyStringTest LANGUAGES CXX)


find_package(Qt5Test REQUIRED)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
enable_testing()
#including the path and source file of the function to be checked
include_directories(H:/extralearning/udemy/cpp/MyString/MyStringClass)

add_executable(MyStringTest tst_mystringtest.cpp
    H:/extralearning/udemy/cpp/MyString/MyStringClass/mystring.cpp)
add_test(NAME MyStringTest COMMAND MyStringTest)

target_link_libraries(MyStringTest PRIVATE Qt5::Test)

