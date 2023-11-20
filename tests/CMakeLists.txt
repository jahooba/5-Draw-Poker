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



add_executable(deckTests
  deckTests.cpp
)

target_link_libraries(deckTests gmock gtest gtest_main)
target_link_libraries(deckTests simpleLibrary)


add_executable(loginTests
 loginTests.cpp
)

target_link_libraries(loginTests gmock gtest gtest_main)
target_link_libraries(loginTests simpleLibrary)
