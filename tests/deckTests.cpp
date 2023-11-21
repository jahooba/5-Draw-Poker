#include "../header/deck.hpp"
#include "gtest/gtest.h"
#include <iostream>
using namespace std;


TEST(DeckOperations, GenerateDeck) {

  Deck deck;
  string strDeck = deck.viewHand();
  string expectedAnswer = "| ♧ 2 | ♤ 2 | ♢ 2 | ♡ 2 | ♧ 3 | ♤ 3 | ♢ 3 | ♡ 3 | ♧ 4 | ♤ 4 | ♢ 4 | ♡ 4 | ♧ 5 | ♤ 5 | ♢ 5 | ♡ 5 | ♧ 6 | ♤ 6 | ♢ 6 | ♡ 6 | ♧ 7 | ♤ 7 | ♢ 7 | ♡ 7 | ♧ 8 | ♤ 8 | ♢ 8 | ♡ 8 | ♧ 9 | ♤ 9 | ♢ 9 | ♡ 9 | ♧ 10 | ♤ 10 | ♢ 10 | ♡ 10 | ♧ J | ♤ J | ♢ J | ♡ J | ♧ Q | ♤ Q | ♢ Q | ♡ Q | ♧ K | ♤ K | ♢ K | ♡ K | ♧ A | ♤ A | ♢ A | ♡ A | ";


  EXPECT_EQ(strDeck, expectedAnswer);
  EXPECT_EQ(deck.getHand().size(), 52);

}

TEST(DeckOperations, DistributeRandomCard) {
  Deck deck;
  Hand hand_one;
  Hand hand_two;

  for (int i = 0; i < 5; i++) {
    hand_one.obtainCard(deck.distributeRandomCard());
    hand_two.obtainCard(deck.distributeRandomCard());
  }

  EXPECT_EQ(hand_one.getHand().size(), 5);
  EXPECT_EQ(hand_two.getHand().size(), 5);
  EXPECT_EQ(deck.getHand().size(), (52-10));  

}

TEST(DeckOperations, ResetDeck) {
  Deck deck;
  Hand hand_one;
  Hand hand_two;

  for (int i = 0; i < 5; i++) {
    hand_one.obtainCard(deck.distributeRandomCard());
    hand_two.obtainCard(deck.distributeRandomCard());
  }

  deck.reset();

  string strDeck = deck.viewHand();
  string expectedAnswer = "| ♧ 2 | ♤ 2 | ♢ 2 | ♡ 2 | ♧ 3 | ♤ 3 | ♢ 3 | ♡ 3 | ♧ 4 | ♤ 4 | ♢ 4 | ♡ 4 | ♧ 5 | ♤ 5 | ♢ 5 | ♡ 5 | ♧ 6 | ♤ 6 | ♢ 6 | ♡ 6 | ♧ 7 | ♤ 7 | ♢ 7 | ♡ 7 | ♧ 8 | ♤ 8 | ♢ 8 | ♡ 8 | ♧ 9 | ♤ 9 | ♢ 9 | ♡ 9 | ♧ 10 | ♤ 10 | ♢ 10 | ♡ 10 | ♧ J | ♤ J | ♢ J | ♡ J | ♧ Q | ♤ Q | ♢ Q | ♡ Q | ♧ K | ♤ K | ♢ K | ♡ K | ♧ A | ♤ A | ♢ A | ♡ A | ";


  EXPECT_EQ(strDeck, expectedAnswer);
  EXPECT_EQ(hand_one.getHand().size(), 5);
  EXPECT_EQ(hand_two.getHand().size(), 5);
  EXPECT_EQ(deck.getHand().size(), 52);

}



int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
