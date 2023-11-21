#include "../header/pokerScoreKey.hpp"

using namespace std;


PokerScoreKey::PokerScoreKey() {
    PokerScoreKey::generateScoreKey();
}

PokerScoreKey::~PokerScoreKey() {
    PokerScoreKey::clear();
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
                                                
                                                //score hand and add to scoreKey
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
    int handScore = 0;
    // Rank values 
    const int SFR = 1000,     
              FOUR = 900,     
              FHR = 800,
              FR = 700,
              SR = 600,
              THREE = 500,
              TWO = 400,
              PAIR = 200,
              HIGH = 100;


    //add points based on what the hand is here

    /*
    SCORING CRITERIA:
    HAND_SCORE = HIGHEST_CONDITION_SCORE + HIGH_CARD_SCORE 

    CONDITION_ORDER FROM HIGHEST -> LOWEST:
    - straight flush
    - 4 of a kind
    - full house
    - flush
    - straight
    - 3 of a kind
    - 2 pair
    - pair
    - high card
    */



    // INSERT CODE HERE!!!
    if (isStraightFlush(h) == true){    //deuce-to-seven low rules (A is always highest)
        int high_card_value = h.getHand().at(4)->value;
        handScore = SFR + high_card_value;

        /*
        --Sums up values of cards
        for (int i = 0; i < h.getHand().size() - 1; i++){
            handScore += h.getHand().at(i)->value;
        }
        handScore += SFR;
        */
    }
    else if (isFourofaKind(h) == true){
        for (int i = 0; i < h.getHand().size() - 1; i++){
            handScore += h.getHand().at(i)->value;
        }
        handScore += FOUR;
        
        /*
        --In the event two hands have the same score, the sum of values would need to be compared
        int high_card_value = h.getHand().at(4)->value;
        int low_card_value = h.getHand().at(0)->value;
        handScore = FOUR + high_card_value + low_card_value;
        */
    }
    // etc.

    return handScore;
}


bool PokerScoreKey::isPair(const Hand& h) {

    for (int i = 0; i < h.getHand().size() - 1; i++) {
        if (h.getHand().at(i)->value == h.getHand().at(i+1)->value) {
            return true;
        }
    }

    return false;
}

bool PokerScoreKey::isTwoPair(const Hand& h) {

    if (PokerScoreKey::isPair(h)) {
        /* 
        two pair means either 
        - " 'a a b b' c " (valid)
        - " a 'b b c c' " (valid)
        - " a a b c c " (valid) 
        since hand is sorted!!!!
        */

        //we already checked leftmost pair when checking for isPair(), therefore only need to check rightmost pair

        // " 'a a b b' c " (valid)
        bool conditionOne = h.getHand().at(2)->value == h.getHand().at(3)->value;

        // " a 'b b c c' " (valid) | " a a b c c " (valid)
        bool conditionTwo = h.getHand().at(3)->value == h.getHand().at(4)->value;

       return (conditionOne || conditionTwo);
    }

    return false;
}  


bool PokerScoreKey::isThreeofaKind(const Hand& h) {
    
    if (PokerScoreKey::isPair(h)) {
        /* 
        three of a kind means either 
        - "a a a b c" (valid)
        - "a b b b c" (valid)
        - "a b c c c" (valid) 
        since hand is sorted!!!!
        */

       //therefore,  

        // "a a a b c" (valid)
        bool conditionOne = h.getHand().at(0)->value == h.getHand().at(1)->value && h.getHand().at(1)->value == h.getHand().at(2)->value;

        // "a b b b c" (valid)
        bool conditionTwo = h.getHand().at(1)->value == h.getHand().at(2)->value && h.getHand().at(2)->value == h.getHand().at(3)->value;

        //"a b c c c" (valid) 
        bool conditionThree = h.getHand().at(2)->value == h.getHand().at(3)->value && h.getHand().at(3)->value == h.getHand().at(4)->value;


       return ((conditionOne || conditionTwo) || conditionThree);
    }

    //if theres no pair, it can't be three of a kind
    return false;
}


bool PokerScoreKey::isStraight(const Hand& h) {
    for (int i = 0; i < h.getHand().size() - 1; i++) {
        if (h.getHand().at(i)->value + 1 != h.getHand().at(i+1)->value) {
            return false;
        }
    }

    return true;
}

bool PokerScoreKey::isFlush(const Hand& h) {
    CardSuit constant = h.getHand().at(0)->suit;

    for (int i = 1; i < h.getHand().size(); i++) {
        if (h.getHand().at(i)->suit != constant) {
            return false;
        }
    }

    return true;

}

bool PokerScoreKey::isFullHouse(const Hand& h) {

    if (PokerScoreKey::isThreeofaKind(h)) {
        /* 
        full house means either 
        - "a a a b b" (valid)
        - "a a b b b" (valid) 
        - "a b b b c" (three of a kind, but invalid full house)
        since hand is sorted!!!!
        */

        //therefore, only need to check endpoints to check if its full house
        bool conditionOne = h.getHand().at(0)->value == h.getHand().at(1)->value;
        bool conditionTwo = h.getHand().at(3)->value == h.getHand().at(4)->value;

        return (conditionOne && conditionTwo);
    }

    //if theres no three of a kind, then it can't be full house
    return false; 
}

bool PokerScoreKey::isFourofaKind(const Hand& h) {

    /* 
    four of a kind means either 
    - "a a a a b" (valid)
    - "a b b b b" (valid) 
    since hand is sorted!!!!
    */
    
    //cards 0-3 have equal value
    bool conditionOne = h.getHand().at(0)->value == h.getHand().at(1)->value && h.getHand().at(1)->value == h.getHand().at(2)->value && h.getHand().at(2)->value == h.getHand().at(3)->value;

    //cards 1-4 have equal value
    bool conditionTwo = h.getHand().at(1)->value == h.getHand().at(2)->value && h.getHand().at(2)->value == h.getHand().at(3)->value && h.getHand().at(3)->value == h.getHand().at(4)->value;


    return (conditionOne || conditionTwo);
}

bool PokerScoreKey::isStraightFlush(const Hand& h) {
    return (PokerScoreKey::isFlush(h) && PokerScoreKey::isStraight(h));
}