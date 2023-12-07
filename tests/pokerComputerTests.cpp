#include "../header/pokerComputer.hpp"
#include "gtest/gtest.h"
#include <iostream>
using namespace std;


TEST(PokerComputerTests, validConstuctor){
  EXPECT_NO_THROW(PokerComputer temp = PokerComputer());
}

TEST(pokerComputerTests, getName1){
  PokerComputer temp = PokerComputer();
  EXPECT_EQ(temp.getName(), "PokerAI");
}

TEST(PokerComputerTests, getName2){
  PokerComputer temp = PokerComputer(300);
  EXPECT_EQ(temp.getName(), "PokerAI");
}

TEST(PokerComputerTests, getBalance1){
  PokerComputer temp = PokerComputer();
  EXPECT_EQ(temp.getPlayerBalance()->getBalance(), 10000);
}

TEST(PokerComputerTests, getBalance2){
  PokerComputer temp = PokerComputer(300);
  EXPECT_EQ(temp.getPlayerBalance()->getBalance(), 300);
}

TEST(PokerComputerTests, updateStats){
  PokerComputer temp = PokerComputer();
  EXPECT_NO_THROW(temp.updateStatistics(20, 300));
}

TEST(PokerComputerTests, printStats){
  PokerComputer temp = PokerComputer();
  EXPECT_NO_THROW(temp.viewStatistics());
}

