cmake_minimum_required(VERSION 3.6)
project(tp_lab_rab_6)

set(CMAKE_CXX_STANDARD 11)

include_directories(src)
add_subdirectory(src)

add_subdirectory(tests)

set(SOURCE_FILES main.cpp)
add_executable(tp_lab_rab_6 ${SOURCE_FILES})
target_link_libraries(tp_lab_rab_6 src)