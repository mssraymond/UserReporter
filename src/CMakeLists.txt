cmake_minimum_required(VERSION 3.15)
project(UserReporter)

# Set policy to use new Python finding method, if supported
if(POLICY CMP0148)
    cmake_policy(SET CMP0148 NEW)
endif()

# Find Python package
set(PYBIND11_FINDPYTHON ON)
find_package(Python COMPONENTS Interpreter Development REQUIRED)

# Define C++ standard
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Find pybind11
find_package(pybind11 REQUIRED)

# Create library
add_library(userReporter_lib STATIC userReporter.cpp)

# Create Python module
pybind11_add_module(userReporter userReporter_pybind.cpp)
target_link_libraries(userReporter PRIVATE userReporter_lib)

# Original C++ executable
add_executable(main main.cpp)
target_link_libraries(main PRIVATE userReporter_lib)