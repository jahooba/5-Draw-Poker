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

add_executable(playerTests
  playerTests.cpp
)

target_link_libraries(playerTests gmock gtest gtest_main)
target_link_libraries(playerTests simpleLibrary)



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



add_executable(pokerTests
  pokerTests.cpp
)

target_link_libraries(pokerTests gmock gtest gtest_main)
target_link_libraries(pokerTests simpleLibrary)


add_executable(pokerScoreKeyTests
 pokerScoreKeyTests.cpp
)

target_link_libraries(pokerScoreKeyTests gmock gtest gtest_main)
target_link_libraries(pokerScoreKeyTests simpleLibrary)

add_executable(statisticsTests
  statisticsTests.cpp
)

target_link_libraries(statisticsTests gmock gtest gtest_main)
target_link_libraries(statisticsTests simpleLibrary)

add_executable(pokerPlayerTests
  pokerPlayerTests.cpp
)

target_link_libraries(pokerPlayerTests gmock gtest gtest_main)
target_link_libraries(pokerPlayerTests simpleLibrary)