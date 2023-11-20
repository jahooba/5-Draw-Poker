add_library(simpleLibrary
  hand.cpp
  deck.cpp
  poker.cpp

  balance.cpp
  player.cpp
  # login.cpp
)

find_library(M_LIB m)
target_link_libraries(simpleLibrary ${M_LIB})

