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

TEST(HandOperations, SortHandMethod){
  Hand hand;

  Card* card_one = new Card(Ten, Hearts);
  hand.obtainCard(card_one);
  Card* card_two = new Card(Two, Spades);
  hand.obtainCard(card_two);
  Card* card_three = new Card(Three, Clubs);
  hand.obtainCard(card_three);
  Card* card_four = new Card(K, Hearts);
  hand.obtainCard(card_four);
  Card* card_five = new Card(J, Diamonds);
  hand.obtainCard(card_five);

  cout << hand.viewHand() << endl;

  EXPECT_EQ("| ♤ 2 | ♧ 3 | ♡ 10 | ♢ J | ♡ K | ", hand.viewHand());
}

TEST(HandOperations, LogicalEqualityOperator) {

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

TEST(HandOperations, DeleteExistingCardMiddle) {

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

  Card* discard = hand_one.distributeCard(J, Diamonds);
  hand_two.obtainCard(discard);


  cout << hand_one.viewHand() << endl;  
  cout << hand_two.viewHand() << endl;

  EXPECT_EQ("| ♧ 2 | ♡ K | ", hand_one.viewHand());
  EXPECT_EQ("| ♢ J | ", hand_two.viewHand());

}

TEST(HandOperations, DeleteExistingCardEnd) {

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

  Card* discard = hand_one.distributeCard(J, Diamonds);
  hand_two.obtainCard(discard);


  cout << hand_one.viewHand() << endl;  
  cout << hand_two.viewHand() << endl;

  EXPECT_EQ("| ♧ 2 | ♡ K | ", hand_one.viewHand());
  EXPECT_EQ("| ♢ J | ", hand_two.viewHand());

}

TEST(HandOperations, DeleteExistingCardStart) {

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

  Card* discard = hand_one.distributeCard(Two, Clubs);
  hand_two.obtainCard(discard);


  cout << hand_one.viewHand() << endl;  
  cout << hand_two.viewHand() << endl;

  EXPECT_EQ("| ♢ J | ♡ K | ", hand_one.viewHand());
  EXPECT_EQ("| ♧ 2 | ", hand_two.viewHand());

}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
