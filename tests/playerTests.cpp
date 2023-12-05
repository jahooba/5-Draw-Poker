#include "gmock/gmock.h"
#include "gtest/gtest.h"
#include "../header/player.hpp"
#include <iostream>
#include <string>
using namespace std;

TEST(playerTests, validPlayer2){
    EXPECT_NO_THROW(Player* play = new Player("Adam", 300));
}

TEST(playerTests, getPlayerBalance){
    Player* player1 = new Player("Adam");
    EXPECT_NO_THROW(player1->getPlayerBalance());
}

TEST(playerTests, getNamePlayer1){
    Player* player1 = new Player("Adam");
    ASSERT_EQ(player1->getName(), "Adam");
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}



