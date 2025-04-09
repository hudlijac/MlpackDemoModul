cmake_minimum_required(VERSION 3.25)
project(demo_modul)

set(CMAKE_CXX_STANDARD 17)

find_package(OpenMP REQUIRED)

link_directories("/home/hudlijac/mlpackmlclassifier/build/src/wif")
link_directories("/usr/local/lib")

include_directories("/home/hudlijac/Nemea-Framework/unirec/include")  
include_directories("/home/hudlijac/mlpackmlclassifier/include")

add_executable(demo_modul main.cpp)

target_link_libraries(demo_modul PRIVATE
        wif              
        OpenMP::OpenMP_CXX
        unirec++
        unirec
        )
