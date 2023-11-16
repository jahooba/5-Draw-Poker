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



int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
