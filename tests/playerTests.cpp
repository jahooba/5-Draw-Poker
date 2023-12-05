#include "gmock/gmock.h"
#include "gtest/gtest.h"
#include "../header/player.hpp"
#include <iostream>
#include <string>
using namespace std;

TEST(playerTests, validPlayer2){
    EXPECT_NO_THROW(Player* play = new Player("Adam", 300));
}

TEST(playerTests, getBalancePlayer1){
    Player* player1 = new Player("Adam");
    EXPECT_NO_THROW(player1->getBalance());
}

TEST(playerTests, getNamePlayer1){
    Player* player1 = new Player("Adam");
    ASSERT_EQ(player1->getName(), "Adam");
}




