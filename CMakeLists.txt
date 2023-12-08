cmake_minimum_required(VERSION 3.2)
project(casino-game)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${PROJECT_BINARY_DIR}/bin")
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${PROJECT_BINARY_DIR}/lib")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${PROJECT_BINARY_DIR}/lib")

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++1y")

include_directories(${CMAKE_SOURCE_DIR}/include)
link_directories(${LIBRARY_OUTPUT_PATH})

include_directories(
  ${CMAKE_SOURCE_DIR}/test/lib/googletest/include/
  ${CMAKE_SOURCE_DIR}/test/lib/googlemock/include/
)

add_subdirectory(src)
add_subdirectory(tests)

add_executable(PokerGame
src/main.cpp src/balance.cpp src/deck.cpp src/hand.cpp src/login.cpp src/player.cpp src/poker.cpp src/pokerComputer.cpp src/pokerPlayer.cpp src/pokerScoreKey.cpp src/statistics.cpp
)