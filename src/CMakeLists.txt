add_library(simpleLibrary
  hand.cpp
  player.cpp
  balance.cpp
)

find_library(M_LIB m)
target_link_libraries(simpleLibrary ${M_LIB})

