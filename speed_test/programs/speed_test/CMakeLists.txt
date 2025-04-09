cmake_minimum_required(VERSION 3.25)
project(speed_test)

set(CMAKE_CXX_STANDARD 17)

find_package(OpenMP REQUIRED)

link_directories("/home/hudlijac/mlpackmlclassifier/build/src/wif")
include_directories("/home/hudlijac/mlpackmlclassifier/include")
include_directories("/usr/include/python3.12")  # Adjust the path to match your Python version
include_directories("/usr/lib/python3/dist-packages/numpy/core/include")

add_executable(speed_test main.cpp)

target_link_libraries(speed_test PRIVATE /usr/lib/x86_64-linux-gnu/libpython3.12.so wif OpenMP::OpenMP_CXX)
