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

TEST(playerTests, getPlayerHand){
    Hand *tempHand = new Hand();
    Player* player1 = new Player("Adam", 300, tempHand);

    Card* card_one = new Card(Ten, Hearts);
    tempHand->obtainCard(card_one);
    Card *card_two = new Card(Four, Hearts);
    tempHand->obtainCard(card_two);
    Card *card_three = new Card(Q, Hearts);
    tempHand->obtainCard(card_three);
    Card *card_four = new Card(A, Hearts);
    tempHand->obtainCard(card_four);
    Card *card_five = new Card(K, Hearts);
    tempHand->obtainCard(card_five);

    cout << player1->getPlayerHand()->viewHand() << endl;

    EXPECT_EQ("| ♡ 4 | ♡ 10 | ♡ Q | ♡ K | ♡ A | ", player1->getPlayerHand()->viewHand());
    //EXPECT_NO_THROW(Player* player1 = new Player("Adam", 300));
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}



