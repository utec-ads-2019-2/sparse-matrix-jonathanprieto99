cmake_minimum_required(VERSION 3.15)
project(sparse-matrix-jonathanprieto99)

set(CMAKE_CXX_STANDARD 17)

add_executable(sparse-matrix-jonathanprieto99 main.cpp node.h matrix.h matrix.cpp tester/tester.cpp tester/tester.h mocker/mocker.cpp mocker/mocker.h)