cmake_minimum_required(VERSION 3.25)
project(mlpack_train)

set(CMAKE_CXX_STANDARD 17)

find_package(OpenMP REQUIRED)

link_directories("/home/hudlijac/mlpackmlclassifier/build/src/wif")
include_directories("/home/hudlijac/mlpackmlclassifier/include")

add_executable(mlpack_train main.cpp)

target_link_libraries(mlpack_train PRIVATE wif OpenMP::OpenMP_CXX boost_serialization armadillo)