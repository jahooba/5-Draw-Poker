#include "gtest/gtest.h"
#include "../header/hand.hpp"
#include "../header/poker.hpp"
#include "../header/pokerScoreKey.hpp"
#include <iostream>
using namespace std;

//Straight Flush Tests
// Straight Flush vs Straight Flush Test
TEST(ScoreHandTests, SF_vs_SF){
    PokerScoreKey key;

    Hand handOne;
    Card* cardOne = new Card(Ten, Spades);
    handOne.obtainCard(cardOne);
    Card* cardTwo = new Card(Nine, Spades);
    handOne.obtainCard(cardTwo);
    Card* cardThree = new Card(Eight, Spades);
    handOne.obtainCard(cardThree);
    Card* cardFour = new Card(Six, Spades);
    handOne.obtainCard(cardFour);
    Card* cardFive = new Card(Seven, Spades);
    handOne.obtainCard(cardFive);


    Hand handTwo;
    Card* cardSix = new Card(Nine, Hearts);
    handTwo.obtainCard(cardSix);
    Card* cardSeven = new Card(Eight, Hearts);
    handTwo.obtainCard(cardSeven);
    Card* cardEight = new Card(Seven, Hearts);
    handTwo.obtainCard(cardEight);
    Card* cardNine = new Card(Five, Hearts);
    handTwo.obtainCard(cardNine);
    Card* cardTen = new Card(Six, Hearts);
    handTwo.obtainCard(cardTen);

    cout << handOne.viewHand() << endl;
    cout << handTwo.viewHand() << endl;
    EXPECT_NO_THROW(key.revealHands(handOne, handTwo););
}


//Four-of-a-Kind Tests
// Low Straight-Flush vs High Four-of-a-Kind Test
TEST(ScoreHandTests, SF_vs_FOUR){
    PokerScoreKey key;

    Hand handOne;
    Card* cardOne = new Card(Two, Spades);
    handOne.obtainCard(cardOne);
    Card* cardTwo = new Card(Three, Spades);
    handOne.obtainCard(cardTwo);
    Card* cardThree = new Card(Four, Spades);
    handOne.obtainCard(cardThree);
    Card* cardFour = new Card(Five, Spades);
    handOne.obtainCard(cardFour);
    Card* cardFive = new Card(Six, Spades);
    handOne.obtainCard(cardFive);


    Hand handTwo;
    Card* cardSix = new Card(A, Spades);
    handTwo.obtainCard(cardSix);
    Card* cardSeven = new Card(A, Hearts);
    handTwo.obtainCard(cardSeven);
    Card* cardEight = new Card(A, Clubs);
    handTwo.obtainCard(cardEight);
    Card* cardNine = new Card(K, Spades);
    handTwo.obtainCard(cardNine);
    Card* cardTen = new Card(A, Diamonds);
    handTwo.obtainCard(cardTen);


    cout << handOne.viewHand() << endl;
    cout << handTwo.viewHand() << endl;
    EXPECT_NO_THROW(key.revealHands(handOne, handTwo));
}
// Four-of-a-Kind vs Four-of-a-Kind Test
TEST(ScoreHandTests, FOUR_vs_FOUR){
    PokerScoreKey key;

    Hand handOne;
    Card* cardOne = new Card(Ten, Spades);
    handOne.obtainCard(cardOne);
    Card* cardTwo = new Card(Ten, Clubs);
    handOne.obtainCard(cardTwo);
    Card* cardThree = new Card(Ten, Diamonds);
    handOne.obtainCard(cardThree);
    Card* cardFour = new Card(Four, Spades);
    handOne.obtainCard(cardFour);
    Card* cardFive = new Card(Ten, Hearts);
    handOne.obtainCard(cardFive);


    Hand handTwo;
    Card* cardSix = new Card(Nine, Spades);
    handTwo.obtainCard(cardSix);
    Card* cardSeven = new Card(Nine, Hearts);
    handTwo.obtainCard(cardSeven);
    Card* cardEight = new Card(Nine, Clubs);
    handTwo.obtainCard(cardEight);
    Card* cardNine = new Card(J, Spades);
    handTwo.obtainCard(cardNine);
    Card* cardTen = new Card(Nine, Diamonds);
    handTwo.obtainCard(cardTen);


    cout << handOne.viewHand() << endl;
    cout << handTwo.viewHand() << endl;
    EXPECT_NO_THROW(key.revealHands(handOne, handTwo));
}


//Full House Tests
// Low Four-of-a-Kind vs High Full House Test
TEST(ScoreHandTests, FOUR_vs_FH){
    PokerScoreKey key;

    Hand handOne;
    Card* cardSix = new Card(Two, Spades);
    handOne.obtainCard(cardSix);
    Card* cardSeven = new Card(Two, Hearts);
    handOne.obtainCard(cardSeven);
    Card* cardEight = new Card(Two, Clubs);
    handOne.obtainCard(cardEight);
    Card* cardNine = new Card(Three, Spades);
    handOne.obtainCard(cardNine);
    Card* cardTen = new Card(Two, Diamonds);
    handOne.obtainCard(cardTen);


    Hand handTwo;
    Card* cardOne = new Card(K, Clubs);
    handTwo.obtainCard(cardOne);
    Card* cardTwo = new Card(A, Spades);
    handTwo.obtainCard(cardTwo);
    Card* cardThree = new Card(K, Hearts);
    handTwo.obtainCard(cardThree);
    Card* cardFour = new Card(A, Clubs);
    handTwo.obtainCard(cardFour);
    Card* cardFive = new Card(A, Diamonds);
    handTwo.obtainCard(cardFive);


    cout << handOne.viewHand() << endl;
    cout << handTwo.viewHand() << endl;
    EXPECT_NO_THROW(key.revealHands(handOne, handTwo));
}
// Full House vs Full House
TEST(ScoreHandTests, FH_vs_FH){
    PokerScoreKey key;

    Hand handOne;
    Card* cardSix = new Card(Six, Spades);
    handOne.obtainCard(cardSix);
    Card* cardSeven = new Card(Six, Hearts);
    handOne.obtainCard(cardSeven);
    Card* cardEight = new Card(Six, Clubs);
    handOne.obtainCard(cardEight);
    Card* cardNine = new Card(Four, Spades);
    handOne.obtainCard(cardNine);
    Card* cardTen = new Card(Four, Diamonds);
    handOne.obtainCard(cardTen);

    Hand handTwo;
    Card* cardOne = new Card(Five, Clubs);
    handTwo.obtainCard(cardOne);
    Card* cardTwo = new Card(Five, Spades);
    handTwo.obtainCard(cardTwo);
    Card* cardThree = new Card(Four, Hearts);
    handTwo.obtainCard(cardThree);
    Card* cardFour = new Card(Four, Clubs);
    handTwo.obtainCard(cardFour);
    Card* cardFive = new Card(Five, Diamonds);
    handTwo.obtainCard(cardFive);


    cout << handOne.viewHand() << endl;
    cout << handTwo.viewHand() << endl;
    EXPECT_NO_THROW(key.revealHands(handOne, handTwo));
}


//Flush Tests
// Flush vs Flush Test
TEST(ScoreHandTests, F_vs_F){
    PokerScoreKey key;

    Hand handOne;
    Card* cardOne = new Card(Five, Spades);
    handOne.obtainCard(cardOne);
    Card* cardTwo = new Card(Seven, Spades);
    handOne.obtainCard(cardTwo);
    Card* cardThree = new Card(Q, Spades);
    handOne.obtainCard(cardThree);
    Card* cardFour = new Card(Ten, Spades);
    handOne.obtainCard(cardFour);
    Card* cardFive = new Card(Two, Spades);
    handOne.obtainCard(cardFive);


    Hand handTwo;
    Card* cardSix = new Card(Four, Clubs);
    handTwo.obtainCard(cardSix);
    Card* cardSeven = new Card(K, Clubs);
    handTwo.obtainCard(cardSeven);
    Card* cardEight = new Card(J, Clubs);
    handTwo.obtainCard(cardEight);
    Card* cardNine = new Card(Three, Clubs);
    handTwo.obtainCard(cardNine);
    Card* cardTen = new Card(Two, Clubs);
    handTwo.obtainCard(cardTen);
    

    cout << handOne.viewHand() << endl;
    cout << handTwo.viewHand() << endl;
    EXPECT_NO_THROW(key.revealHands(handOne, handTwo));
}
// Flush vs Flush Test - same values, different suit
TEST(ScoreHandTests, F_vs_F_sameValues){
    PokerScoreKey key;

    Hand handOne;
    Card* cardOne = new Card(Five, Spades);
    handOne.obtainCard(cardOne);
    Card* cardTwo = new Card(Seven, Spades);
    handOne.obtainCard(cardTwo);
    Card* cardThree = new Card(Q, Spades);
    handOne.obtainCard(cardThree);
    Card* cardFour = new Card(Ten, Spades);
    handOne.obtainCard(cardFour);
    Card* cardFive = new Card(Two, Spades);
    handOne.obtainCard(cardFive);


    Hand handTwo;
    Card* cardSix = new Card(Five, Clubs);
    handTwo.obtainCard(cardSix);
    Card* cardSeven = new Card(Seven, Clubs);
    handTwo.obtainCard(cardSeven);
    Card* cardEight = new Card(Q, Clubs);
    handTwo.obtainCard(cardEight);
    Card* cardNine = new Card(Ten, Clubs);
    handTwo.obtainCard(cardNine);
    Card* cardTen = new Card(Two, Clubs);
    handTwo.obtainCard(cardTen);


    cout << handOne.viewHand() << endl;
    cout << handTwo.viewHand() << endl;
    EXPECT_NO_THROW(key.revealHands(handOne, handTwo));
}

//Straight Tests
// Straight vs Straight Test
TEST(ScoreHandTests, S_vs_S){
    PokerScoreKey key;

    Hand handOne;
    Card* cardOne = new Card(Ten, Spades);
    handOne.obtainCard(cardOne);
    Card* cardTwo = new Card(Nine, Clubs);
    handOne.obtainCard(cardTwo);
    Card* cardThree = new Card(Eight, Hearts);
    handOne.obtainCard(cardThree);
    Card* cardFour = new Card(Six, Diamonds);
    handOne.obtainCard(cardFour);
    Card* cardFive = new Card(Seven, Spades);
    handOne.obtainCard(cardFive);


    Hand handTwo;
    Card* cardSix = new Card(Nine, Hearts);
    handTwo.obtainCard(cardSix);
    Card* cardSeven = new Card(Eight, Diamonds);
    handTwo.obtainCard(cardSeven);
    Card* cardEight = new Card(Seven, Clubs);
    handTwo.obtainCard(cardEight);
    Card* cardNine = new Card(Five, Hearts);
    handTwo.obtainCard(cardNine);
    Card* cardTen = new Card(Six, Hearts);
    handTwo.obtainCard(cardTen);


    cout << handOne.viewHand() << endl;
    cout << handTwo.viewHand() << endl;
    EXPECT_NO_THROW(key.revealHands(handOne, handTwo));
}
// Straight vs Straight Test - same values
TEST(ScoreHandTests, S_vs_S_sameValues){
    PokerScoreKey key;

    Hand handOne;
    Card* cardOne = new Card(Ten, Spades);
    handOne.obtainCard(cardOne);
    Card* cardTwo = new Card(Nine, Clubs);
    handOne.obtainCard(cardTwo);
    Card* cardThree = new Card(Eight, Hearts);
    handOne.obtainCard(cardThree);
    Card* cardFour = new Card(Six, Diamonds);
    handOne.obtainCard(cardFour);
    Card* cardFive = new Card(Seven, Spades);
    handOne.obtainCard(cardFive);


    Hand handTwo;
    Card* cardSix = new Card(Ten, Hearts);
    handTwo.obtainCard(cardSix);
    Card* cardSeven = new Card(Nine, Diamonds);
    handTwo.obtainCard(cardSeven);
    Card* cardEight = new Card(Eight, Clubs);
    handTwo.obtainCard(cardEight);
    Card* cardNine = new Card(Six, Hearts);
    handTwo.obtainCard(cardNine);
    Card* cardTen = new Card(Seven, Hearts);
    handTwo.obtainCard(cardTen);


    cout << handOne.viewHand() << endl;
    cout << handTwo.viewHand() << endl;
    EXPECT_NO_THROW(key.revealHands(handOne, handTwo));
}
// Flush vs Straight
TEST(ScoreHandTests, F_vs_S){
    PokerScoreKey key;

    Hand handOne;
    Card* cardOne = new Card(Ten, Spades);
    handOne.obtainCard(cardOne);
    Card* cardTwo = new Card(Two, Spades);
    handOne.obtainCard(cardTwo);
    Card* cardThree = new Card(Eight, Spades);
    handOne.obtainCard(cardThree);
    Card* cardFour = new Card(A, Spades);
    handOne.obtainCard(cardFour);
    Card* cardFive = new Card(Seven, Spades);
    handOne.obtainCard(cardFive);


    Hand handTwo;
    Card* cardSix = new Card(Nine, Hearts);
    handTwo.obtainCard(cardSix);
    Card* cardSeven = new Card(Eight, Diamonds);
    handTwo.obtainCard(cardSeven);
    Card* cardEight = new Card(Seven, Spades);
    handTwo.obtainCard(cardEight);
    Card* cardNine = new Card(Five, Hearts);
    handTwo.obtainCard(cardNine);
    Card* cardTen = new Card(Six, Clubs);
    handTwo.obtainCard(cardTen);

    cout << handOne.viewHand() << endl;
    cout << handTwo.viewHand() << endl;
    EXPECT_NO_THROW(key.revealHands(handOne, handTwo));
}


int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
