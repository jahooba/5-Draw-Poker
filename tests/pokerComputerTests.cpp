#include "../header/pokerComputer.hpp"
#include "gtest/gtest.h"
#include <iostream>
using namespace std;


TEST(PokerComputerTests, validConstuctor){
  EXPECT_NO_THROW(PokerComputer temp = PokerComputer());
}

TEST(PokerComputerTests, getName1){
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

TEST(PokerComputerActions, moveFromEmptyHand) {
  PokerComputer temp = PokerComputer();

  PokerAction* completedMove = temp.pokerMove();

  cout << "Hand Score: " << temp.getHandScore() << endl;
  cout << "Bet Amount: " << completedMove->bet << endl;
  cout << "Move Type: " << completedMove->type << endl;

  EXPECT_TRUE(completedMove->bet == 0);
  EXPECT_TRUE(completedMove->type == Check);
}

TEST(PokerComputerActions, VeryGoodHand) {
  Hand* handOne = new Hand();
  Card* cardOne = new Card(Ten, Spades);
  handOne->obtainCard(cardOne);
  Card* cardTwo = new Card(Nine, Spades);
  handOne->obtainCard(cardTwo);
  Card* cardThree = new Card(Eight, Spades);
  handOne->obtainCard(cardThree);
  Card* cardFour = new Card(Six, Spades);
  handOne->obtainCard(cardFour);
  Card* cardFive = new Card(Seven, Spades);
  handOne->obtainCard(cardFive);

  PokerComputer temp = PokerComputer(1000, handOne);

  temp.setCurrMaxBet(100);
  temp.setAbsMaxBet(1000000000);
  PokerAction* completedMove = temp.pokerMove();

  cout << "Hand Score: " << temp.getHandScore() << endl;
  cout << "Bet Amount: " << completedMove->bet << endl;
  cout << "Move Type: " << completedMove->type << endl;

  EXPECT_TRUE(completedMove->bet >= 0);
  EXPECT_TRUE(completedMove->type == Bet);
  EXPECT_DOUBLE_EQ(temp.getPlayerBalance()->getBalance(), 1000 - 108);
}

TEST(PokerComputerActions, MediumHand) {
  Hand* handOne = new Hand();
  Card* cardOne = new Card(Ten, Spades);
  handOne->obtainCard(cardOne);
  Card* cardTwo = new Card(Nine, Clubs);
  handOne->obtainCard(cardTwo);
  Card* cardThree = new Card(Eight, Hearts);
  handOne->obtainCard(cardThree);
  Card* cardFour = new Card(Six, Diamonds);
  handOne->obtainCard(cardFour);
  Card* cardFive = new Card(Seven, Spades);
  handOne->obtainCard(cardFive);

  PokerComputer temp = PokerComputer(1000, handOne);

  temp.setCurrMaxBet(100);
  temp.setAbsMaxBet(1000000000);
  PokerAction* completedMove = temp.pokerMove();

  cout << "Hand Score: " << temp.getHandScore() << endl;
  cout << "Bet Amount: " << completedMove->bet << endl;
  cout << "Move Type: " << completedMove->type << endl;

  EXPECT_TRUE(completedMove->bet >= 0);
  EXPECT_TRUE(completedMove->type == Bet);
  EXPECT_DOUBLE_EQ(temp.getPlayerBalance()->getBalance(), 1000 - 135);
}

TEST(PokerComputerActions, VeryBadHand) {
  Hand* handOne = new Hand();
  Card* cardOne = new Card(Two, Spades);
  handOne->obtainCard(cardOne);
  Card* cardTwo = new Card(Eight, Clubs);
  handOne->obtainCard(cardTwo);
  Card* cardThree = new Card(Ten, Clubs);
  handOne->obtainCard(cardThree);
  Card* cardFour = new Card(J, Diamonds);
  handOne->obtainCard(cardFour);
  Card* cardFive = new Card(K, Hearts);
  handOne->obtainCard(cardFive);

  PokerComputer temp = PokerComputer(1000, handOne);

  temp.setCurrMaxBet(100);
  temp.setAbsMaxBet(1000000000);
  PokerAction* completedMove = temp.pokerMove();

  cout << "Hand Score: " << temp.getHandScore() << endl;
  cout << "Bet Amount: " << completedMove->bet << endl;
  cout << "Move Type: " << completedMove->type << endl;

  EXPECT_TRUE(completedMove->bet >= 0);
  EXPECT_TRUE(completedMove->type == Call);
  EXPECT_DOUBLE_EQ(temp.getPlayerBalance()->getBalance(), 1000 - 100);
}

TEST(PokerComputerActions, GoingBankrupt) {
  Hand* handOne = new Hand();
  Card* cardOne = new Card(Ten, Spades);
  handOne->obtainCard(cardOne);
  Card* cardTwo = new Card(Nine, Spades);
  handOne->obtainCard(cardTwo);
  Card* cardThree = new Card(Eight, Spades);
  handOne->obtainCard(cardThree);
  Card* cardFour = new Card(Six, Spades);
  handOne->obtainCard(cardFour);
  Card* cardFive = new Card(Seven, Spades);
  handOne->obtainCard(cardFive);

  PokerComputer temp = PokerComputer(1500, handOne);
  temp.setCurrMaxBet(5);
  temp.setAbsMaxBet(1000000000);

  PokerAction* completedMove = temp.pokerMove();
  cout << "Hand Score: " << temp.getHandScore() << endl;
  cout << "Bet Amount: " << completedMove->bet << endl;
  cout << "Move Type: " << completedMove->type << endl;

  completedMove = temp.pokerMove();
  cout << "Hand Score: " << temp.getHandScore() << endl;
  cout << "Bet Amount: " << completedMove->bet << endl;
  cout << "Move Type: " << completedMove->type << endl;

  completedMove = temp.pokerMove();
  cout << "Hand Score: " << temp.getHandScore() << endl;
  cout << "Bet Amount: " << completedMove->bet << endl;
  cout << "Move Type: " << completedMove->type << endl;

  completedMove = temp.pokerMove();
  cout << "Hand Score: " << temp.getHandScore() << endl;
  cout << "Bet Amount: " << completedMove->bet << endl;
  cout << "Move Type: " << completedMove->type << endl;

  completedMove = temp.pokerMove();
  cout << "Hand Score: " << temp.getHandScore() << endl;
  cout << "Bet Amount: " << completedMove->bet << endl;
  cout << "Move Type: " << completedMove->type << endl;

  EXPECT_TRUE(completedMove->type == Bet);

  completedMove = temp.pokerMove();
  cout << "Hand Score: " << temp.getHandScore() << endl;
  cout << "Bet Amount: " << completedMove->bet << endl;
  cout << "Move Type: " << completedMove->type << endl;

  EXPECT_TRUE(completedMove->bet == 1500);
  EXPECT_TRUE(completedMove->type == Check);
  EXPECT_DOUBLE_EQ(temp.getPlayerBalance()->getBalance(), 0);

}

TEST(PokerComputerActions, MaxBetReachedWithoutBankrupt) {
  Hand* handOne = new Hand();
  Card* cardOne = new Card(Ten, Spades);
  handOne->obtainCard(cardOne);
  Card* cardTwo = new Card(Nine, Spades);
  handOne->obtainCard(cardTwo);
  Card* cardThree = new Card(Eight, Spades);
  handOne->obtainCard(cardThree);
  Card* cardFour = new Card(Six, Spades);
  handOne->obtainCard(cardFour);
  Card* cardFive = new Card(Seven, Spades);
  handOne->obtainCard(cardFive);

  PokerComputer temp = PokerComputer(1500, handOne);
  temp.setCurrMaxBet(5);
  temp.setAbsMaxBet(500);

  PokerAction* completedMove = temp.pokerMove();
  cout << "Hand Score: " << temp.getHandScore() << endl;
  cout << "Bet Amount: " << completedMove->bet << endl;
  cout << "Move Type: " << completedMove->type << endl;

  completedMove = temp.pokerMove();
  cout << "Hand Score: " << temp.getHandScore() << endl;
  cout << "Bet Amount: " << completedMove->bet << endl;
  cout << "Move Type: " << completedMove->type << endl;

  completedMove = temp.pokerMove();
  cout << "Hand Score: " << temp.getHandScore() << endl;
  cout << "Bet Amount: " << completedMove->bet << endl;
  cout << "Move Type: " << completedMove->type << endl;

  completedMove = temp.pokerMove();
  cout << "Hand Score: " << temp.getHandScore() << endl;
  cout << "Bet Amount: " << completedMove->bet << endl;
  cout << "Move Type: " << completedMove->type << endl;

  completedMove = temp.pokerMove();
  cout << "Hand Score: " << temp.getHandScore() << endl;
  cout << "Bet Amount: " << completedMove->bet << endl;
  cout << "Move Type: " << completedMove->type << endl;

  completedMove = temp.pokerMove();
  cout << "Hand Score: " << temp.getHandScore() << endl;
  cout << "Bet Amount: " << completedMove->bet << endl;
  cout << "Move Type: " << completedMove->type << endl;

  EXPECT_TRUE(completedMove->bet == 500);
  EXPECT_TRUE(completedMove->type == Check);
  EXPECT_DOUBLE_EQ(temp.getPlayerBalance()->getBalance(), 1000);
}

