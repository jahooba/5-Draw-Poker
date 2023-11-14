#include "../header/hand.hpp"
#include "../src/hand.cpp"
#include "gtest/gtest.h"

Hand::obtainCard(Card* card){
        vector.push_back(card);
}

Hand::viewHand(){
        for (auto x:hand) {
                cout << x << " ";
        }
}

Hand::clearHand(){
        for (auto x:hand) {
                hand.pop_back(x);
        }
}

TEST(CardTests, obtainCardTest){
	Card *card = 
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
