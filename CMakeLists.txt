cmake_minimum_required(VERSION 3.26)
project(Numerical_Methods_DE)

set(CMAKE_CXX_STANDARD 14)

add_executable(Numerical_Methods_DE
        first_order_ODE.cpp
        system_of_ODE.cpp)
