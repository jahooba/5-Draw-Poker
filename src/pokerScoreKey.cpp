#include "../header/pokerScoreKey.hpp"

using namespace std;


PokerScoreKey::PokerScoreKey() {
    PokerScoreKey::generateScoreKey();
}

int PokerScoreKey::at(const string& handStr) const {
    return scoreKey.at(handStr);
}

void PokerScoreKey::clear() {
    scoreKey.clear();
}

void PokerScoreKey::generateScoreKey() {

    Hand temporaryHand;

    //card one
    for (int valueOne = Two; valueOne <= A; valueOne++) {

        CardValue value1 = static_cast<CardValue>(valueOne); 

        for (int suitOne = Clubs; suitOne <= Hearts; suitOne++) {
            CardSuit suit1 = static_cast<CardSuit>(suitOne);

            //card 2
            for (int valueTwo = Two; valueTwo <= A; valueTwo++) {
                CardValue value2 = static_cast<CardValue>(valueTwo);

                for (int suitTwo = Clubs; suitTwo <= Hearts; suitTwo++) {
                    CardSuit suit2 = static_cast<CardSuit>(suitTwo);

                    //card 3
                    for (int valueThree = Two; valueThree <= A; valueThree++) {
                        CardValue value3 = static_cast<CardValue>(valueThree);

                        for (int suitThree = Clubs; suitThree <= Hearts; suitThree++) {
                            CardSuit suit3 = static_cast<CardSuit>(suitThree);

                            //card 4
                            for (int valueFour = Two; valueFour <= A; valueFour++) {
                                CardValue value4 = static_cast<CardValue>(valueFour);

                                for (int suitFour = Clubs; suitFour <= Hearts; suitFour++) {
                                    CardSuit suit4 = static_cast<CardSuit>(suitFour);

                                    //card 5
                                    for (int valueFive = Two; valueFive <= A; valueFive++) {
                                        CardValue value5 = static_cast<CardValue>(valueFive);

                                        for (int suitFive = Clubs; suitFive <= Hearts; suitFive++) {
                                            CardSuit suit5 = static_cast<CardSuit>(suitFive);

                                            //generate hand
                                            Card* cardOne = new Card(value1, suit1);
                                            Card* cardTwo = new Card(value2, suit2);
                                            Card* cardThree = new Card(value3, suit3);
                                            Card* cardFour = new Card(value4, suit4);
                                            Card* cardFive = new Card(value5, suit5);

                                            //add cards to hand
                                            temporaryHand.obtainCard(cardOne);
                                            temporaryHand.obtainCard(cardTwo);
                                            temporaryHand.obtainCard(cardThree);
                                            temporaryHand.obtainCard(cardFour);
                                            temporaryHand.obtainCard(cardFive);
                                            
                                            string strHand = temporaryHand.viewHand();

                                            //only score hand if its not found
                                            if (scoreKey.count(strHand) == 0) {
                                                
                                                //score hand
                                                int handScore = PokerScoreKey::scoreHand(temporaryHand);
                                                scoreKey[strHand] = handScore;   
                                            }

                                            temporaryHand.clearHand(); //clear hand after every generation
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }


    temporaryHand.clearHand(); //just to be safe haha
}


int PokerScoreKey::scoreHand(const Hand& h) {
    string handStr = h.viewHand();

    return 1;
}

bool PokerScoreKey::isStraight(const Hand& h) {
    return false;
}

bool PokerScoreKey::isFlush(const Hand& h) {
    return true;
}

bool PokerScoreKey::isFullHouse(const Hand& h) {
    return false;
}

bool PokerScoreKey::isFourofaKind(const Hand& h) {
    int count = 0;


    for (const Card* item : h.getHand()) {
        for (int i = 0; i < 5; i++) {
            if (item->value == h.getHand().at(i)->value) {
                count++;
            }
        }

        if (count == 4) {
            return true;
        }
    }
    
    return false;
}

bool PokerScoreKey::isStraightFlush(const Hand& h) {

    return (PokerScoreKey::isFlush(h) && PokerScoreKey::isStraight(h));
}