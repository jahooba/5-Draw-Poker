cmake_minimum_required(VERSION 3.20)
project(github-actions)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${PROJECT_BINARY_DIR}/bin")
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${PROJECT_BINARY_DIR}/lib")
add_subdirectory(googletest)

add_executable(runAllTests
  tests.cpp deckTests.cpp handTests.cpp loginTests.cpp playerTests.cpp pokerPlayerTests.cpp pokerScoreKeyTests.cpp pokerTests.cpp pokerComputerTests.cpp statisticsTests.cpp balanceTests.cpp
)

target_link_libraries(runAllTests gmock gtest gtest_main)
target_link_libraries(runAllTests simpleLibrary)

add_executable(handTests
  tests.cpp handTests.cpp
)

target_link_libraries(handTests gmock gtest gtest_main)
target_link_libraries(handTests simpleLibrary)

add_executable(playerTests
  tests.cpp playerTests.cpp
)

target_link_libraries(playerTests gmock gtest gtest_main)
target_link_libraries(playerTests simpleLibrary)

add_executable(deckTests
  tests.cpp deckTests.cpp
)

target_link_libraries(deckTests gmock gtest gtest_main)
target_link_libraries(deckTests simpleLibrary)


add_executable(loginTests
  tests.cpp loginTests.cpp
)

target_link_libraries(loginTests gmock gtest gtest_main)
target_link_libraries(loginTests simpleLibrary)

add_executable(pokerTests
  tests.cpp pokerTests.cpp
)

target_link_libraries(pokerTests gmock gtest gtest_main)
target_link_libraries(pokerTests simpleLibrary)


add_executable(pokerActionTests
  tests.cpp pokerActionTests.cpp
)

target_link_libraries(pokerActionTests gmock gtest gtest_main)
target_link_libraries(pokerActionTests simpleLibrary)


add_executable(pokerScoreKeyTests
  tests.cpp pokerScoreKeyTests.cpp
)

target_link_libraries(pokerScoreKeyTests gmock gtest gtest_main)
target_link_libraries(pokerScoreKeyTests simpleLibrary)


add_executable(pokerPlayerTests
  tests.cpp pokerPlayerTests.cpp
)

target_link_libraries(pokerPlayerTests gmock gtest gtest_main)
target_link_libraries(pokerPlayerTests simpleLibrary)

add_executable(pokerComputerTests
  tests.cpp pokerComputerTests.cpp
)

target_link_libraries(pokerComputerTests gmock gtest gtest_main)
target_link_libraries(pokerComputerTests simpleLibrary)


add_executable(statisticsTests
  tests.cpp statisticsTests.cpp
)

target_link_libraries(statisticsTests gmock gtest gtest_main)
target_link_libraries(statisticsTests simpleLibrary)


add_executable(balanceTests
  tests.cpp balanceTests.cpp
)


target_link_libraries(balanceTests gmock gtest gtest_main)
target_link_libraries(balanceTests simpleLibrary)


