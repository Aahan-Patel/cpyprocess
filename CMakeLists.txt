cmake_minimum_required(VERSION 3.4...3.18)
project(cpyprocess)
add_subdirectory(pybind11)
pybind11_add_module(cpyprocess src/main.cpp)
