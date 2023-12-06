#include "gtest/gtest.h"
#include "../header/player.hpp"
#include <iostream>
#include <string>
using namespace std;

TEST(playerTests, validPlayer2){
    Player* play;
    EXPECT_NO_THROW(play = new Player("Adam", 300));
    delete play;
}

TEST(playerTests, getPlayerBalance){
    Player* player1 = new Player("Adam");
    EXPECT_NO_THROW(player1->getPlayerBalance());
    delete player1;
}

TEST(playerTests, getNamePlayer1){
    Player* player1 = new Player("Adam");
    ASSERT_EQ(player1->getName(), "Adam");
    delete player1;
}


TEST(playerTests, destructor){
    Player* player1 = new Player("Adam", 300, new Hand());
    ASSERT_NO_THROW(delete player1);
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

    //cout << player1->getPlayerHand()->viewHand() << endl;

    EXPECT_EQ("| ♡ 4 | ♡ 10 | ♡ Q | ♡ K | ♡ A | ", player1->getPlayerHand()->viewHand());
    delete player1;
}



