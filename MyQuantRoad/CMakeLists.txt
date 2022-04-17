cmake_minimum_required(VERSION 3.10.2)

project(01.exe)

add_executable(${PROJECT_NAME} 01.cpp)

include_directories(/usr/include)
link_directories(/usr/lib)

target_link_libraries(${PROJECT_NAME} libQuantLib.so)