cmake_minimum_required(VERSION 3.10)
project(raytracing)

# Force the compiler to use modern C++ standards
# set(CMAKE_CXX_STANDARD 17)
# set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Tell CMake to build an executable named "inOneWeekend" from your main.cc file
add_executable(oraytrace main.cc)
