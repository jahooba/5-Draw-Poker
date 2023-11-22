add_library(simpleLibrary
  hand.cpp
  deck.cpp
  poker.cpp
  pokerScoreKey.cpp
  balance.cpp
  player.cpp
  login.cpp
  statistics.cpp
  pokerPlayer.cpp
)

find_library(M_LIB m)
target_link_libraries(simpleLibrary ${M_LIB})

