#include "../header/hand.hpp"
#include "gtest/gtest.h"
#include <iostream>
using namespace std;


TEST(HandOperations, ObtainMultipleCards) {

  Hand hand;
  Card* card_one = new Card(Two, Clubs);
  Card* card_two = new Card(J, Diamonds);

  hand.obtainCard(card_one);
  hand.obtainCard(card_two);

  string strhand = hand.viewHand();

  cout << strhand << endl;

  EXPECT_EQ(strhand, "| ♧ 2 | ♢ J | ");

}

TEST(HandOperations, EqualityOperator) {

  Hand hand_one;
  Hand hand_two;
  Card* card_one = new Card(Two, Clubs);
  Card* card_two = new Card(J, Diamonds);
  Card* card_three = new Card(Two, Clubs);
  Card* card_four = new Card(J, Diamonds);

  hand_one.obtainCard(card_one);
  hand_one.obtainCard(card_two);

  hand_two.obtainCard(card_three);
  hand_two.obtainCard(card_four);

  string strhand_one = hand_one.viewHand();
  string strhand_two = hand_two.viewHand();

  cout << strhand_one << endl;
  cout << strhand_two << endl;

  EXPECT_EQ(hand_one, hand_two);

}

TEST(HandOperations, DeleteExistingCard) {

  Hand hand_one;
  Hand hand_two;
  Card* card_one = new Card(Two, Clubs);
  Card* card_two = new Card(J, Diamonds);
  Card* card_three = new Card(K, Hearts);

  hand_one.obtainCard(card_one);
  hand_one.obtainCard(card_two);
  hand_one.obtainCard(card_three);
  
  cout << hand_one.viewHand() << endl;
  cout << hand_two.viewHand() << endl;

  EXPECT_EQ("| ♧ 2 | ♢ J | ♡ K | ", hand_one.viewHand());
  EXPECT_EQ("Empty!", hand_two.viewHand());

  Card* discard = hand_one.distributeCard(K, Hearts);
  hand_two.obtainCard(discard);


  cout << hand_one.viewHand() << endl;  
  cout << hand_two.viewHand() << endl;

  EXPECT_EQ("| ♧ 2 | ♢ J | ", hand_one.viewHand());
  EXPECT_EQ("| ♡ K | ", hand_two.viewHand());

}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
