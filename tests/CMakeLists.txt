cmake_minimum_required(VERSION 3.20)
project(github-actions)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${PROJECT_BINARY_DIR}/bin")
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${PROJECT_BINARY_DIR}/lib")
add_subdirectory(googletest)

add_executable(handTests
  handTests.cpp
)

target_link_libraries(handTests gmock gtest gtest_main)
target_link_libraries(handTests simpleLibrary)

