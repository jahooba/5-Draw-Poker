#include "gtest/gtest.h"
#include "../header/hand.hpp"
#include "../header/poker.hpp"
#include "../header/pokerScoreKey.hpp"
#include <iostream>
using namespace std;

//Straight Flush Tests
// Royal Flush Test
TEST(ScoreHandTests, RoyalFlush){
    Hand hand;
    PokerScoreKey key;

    Card* cardOne = new Card(A, Spades);
    hand.obtainCard(cardOne);
    Card* cardTwo = new Card(K, Spades);
    hand.obtainCard(cardTwo);
    Card* cardThree = new Card(Q, Spades);
    hand.obtainCard(cardThree);
    Card* cardFour = new Card(J, Spades);
    hand.obtainCard(cardFour);
    Card* cardFive = new Card(Ten, Spades);
    hand.obtainCard(cardFive);
    
    const int hand_score = key.scoreHand(hand);
    cout << hand.viewHand() << "= " << hand_score << endl;

    EXPECT_EQ(hand_score, 1014);
}
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

    const int handOne_score = key.scoreHand(handOne);
    cout << handOne.viewHand() << "= " << handOne_score << endl;


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

    const int handTwo_score = key.scoreHand(handTwo);
    cout << handTwo.viewHand() << "= " << handTwo_score << endl;

    cout << handOne_score << " > " << handTwo_score << endl;
    EXPECT_GT(handOne_score, handTwo_score);
}


//Four-of-a-Kind Tests
// Quad-Aces-and-King Test
TEST(ScoreHandTests, QuadAcesAndKing){
    Hand hand;
    PokerScoreKey key;

    Card* cardOne = new Card(A, Spades);
    hand.obtainCard(cardOne);
    Card* cardTwo = new Card(A, Hearts);
    hand.obtainCard(cardTwo);
    Card* cardThree = new Card(A, Clubs);
    hand.obtainCard(cardThree);
    Card* cardFour = new Card(K, Spades);
    hand.obtainCard(cardFour);
    Card* cardFive = new Card(A, Diamonds);
    hand.obtainCard(cardFive);
    
    const int hand_score = key.scoreHand(hand);
    cout << hand.viewHand() << "= " << hand_score << endl;

    EXPECT_EQ(hand_score, 969);
}
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

    const int handOne_score = key.scoreHand(handOne);
    cout << handOne.viewHand() << "= " << handOne_score << endl;


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

    const int handTwo_score = key.scoreHand(handTwo);
    cout << handTwo.viewHand() << "= " << handTwo_score << endl;

    cout << handOne_score << " > " << handTwo_score << endl;
    EXPECT_GT(handOne_score, handTwo_score);
}


//Full House Tests
// Aces-full-of-Kings Test
TEST(ScoreHandTests, AcesFullKings){
    Hand hand;
    PokerScoreKey key;
    
    Card* cardOne = new Card(A, Spades);
    hand.obtainCard(cardOne);
    Card* cardTwo = new Card(K, Clubs);
    hand.obtainCard(cardTwo);
    Card* cardThree = new Card(A, Hearts);
    hand.obtainCard(cardThree);
    Card* cardFour = new Card(K, Diamonds);
    hand.obtainCard(cardFour);
    Card* cardFive = new Card(A, Hearts);
    hand.obtainCard(cardFive);

    const int hand_score = key.scoreHand(hand);
    cout << hand.viewHand() << "= " << hand_score << endl;

    EXPECT_EQ(hand_score, 868);
}
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

    const int handOne_score = key.scoreHand(handOne);
    cout << handOne.viewHand() << "= " << handOne_score << endl;


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

    const int handTwo_score = key.scoreHand(handTwo);
    cout << handTwo.viewHand() << "= " << handTwo_score << endl;


    cout << handOne_score << " > " << handTwo_score << endl;
    EXPECT_GT(handOne_score, handTwo_score);
}


//Flush Tests
TEST(ScoreHandTests, Flush){
    Hand hand;
    PokerScoreKey key;

    Card* cardOne = new Card(Five, Spades);
    hand.obtainCard(cardOne);
    Card* cardTwo = new Card(Seven, Spades);
    hand.obtainCard(cardTwo);
    Card* cardThree = new Card(Q, Spades);
    hand.obtainCard(cardThree);
    Card* cardFour = new Card(Ten, Spades);
    hand.obtainCard(cardFour);
    Card* cardFive = new Card(Two, Spades);
    hand.obtainCard(cardFive);
    
    const int hand_score = key.scoreHand(hand);
    cout << hand.viewHand() << "= " << hand_score << endl;

    EXPECT_EQ(hand_score, 736);
}
// Flush vs Flush
TEST(ScoreHandTests, FR_vs_FR){
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
    
    const int handOne_score = key.scoreHand(handOne);
    cout << handOne.viewHand() << "= " << handOne_score << endl;


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
    
    const int handTwo_score = key.scoreHand(handTwo);
    cout << handTwo.viewHand() << "= " << handTwo_score << endl;
    

    EXPECT_GT(handOne_score, handTwo_score);
}
// Flush vs Flush - same values, different suit
TEST(ScoreHandTests, FR_EQ_FR_sameValues){
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
    
    const int handOne_score = key.scoreHand(handOne);
    cout << handOne.viewHand() << "= " << handOne_score << endl;


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
    
    const int handTwo_score = key.scoreHand(handTwo);
    cout << handTwo.viewHand() << "= " << handTwo_score << endl;
    

    EXPECT_EQ(handOne_score, handTwo_score);
    cout << "Pot split between tied hands!" << endl;
}
// Flush vs Flush - same score, different suit
TEST(ScoreHandTests, FR_EQ_FR_sameScores){
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
    
    const int handOne_score = key.scoreHand(handOne);
    cout << handOne.viewHand() << "= " << handOne_score << endl;


    Hand handTwo;
    Card* cardSix = new Card(Four, Clubs);
    handTwo.obtainCard(cardSix);
    Card* cardSeven = new Card(K, Clubs);
    handTwo.obtainCard(cardSeven);
    Card* cardEight = new Card(A, Clubs);
    handTwo.obtainCard(cardEight);
    Card* cardNine = new Card(Three, Clubs);
    handTwo.obtainCard(cardNine);
    Card* cardTen = new Card(Two, Clubs);
    handTwo.obtainCard(cardTen);
    
    const int handTwo_score = key.scoreHand(handTwo);
    cout << handTwo.viewHand() << "= " << handTwo_score << endl;
    

    EXPECT_EQ(handOne_score, handTwo_score);
    cout << handOne_score << " = " << handTwo_score << endl;

    int handOne_highest = handOne.getHand().at(4)->value;
    int handTwo_highest = handTwo.getHand().at(4)->value;
    EXPECT_LT(handOne_highest, handTwo_highest);
    cout << handOne_highest << " < " << handTwo_highest << "-->handTwo would win" << endl;
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
