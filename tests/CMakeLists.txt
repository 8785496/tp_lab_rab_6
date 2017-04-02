add_subdirectory(googletest)
include_directories(googletest/include)

set(SOURCE_FILES tests.cpp)
add_executable(run_tests ${SOURCE_FILES})

target_link_libraries(run_tests gtest gtest_main)
target_link_libraries(run_tests src)