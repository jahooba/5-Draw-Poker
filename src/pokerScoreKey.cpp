#include "../header/pokerScoreKey.hpp"

using namespace std;

PokerScoreKey::PokerScoreKey() {}

PokerScoreKey::~PokerScoreKey() {}

void PokerScoreKey::revealHands(Hand& handOne, Hand& handTwo){
    int handOne_rank = rankHand(handOne);
    int handTwo_rank = rankHand(handTwo);

    if (handOne_rank > handTwo_rank)
        cout << "Player 1 wins." << endl;
    else if (handOne_rank < handTwo_rank)
        cout << "Player 2 wins." << endl;
    else{
        if (handOne_rank == 1000){
            if (handOne.getHand().at(4)->value > handTwo.getHand().at(4)->value){
                cout << "Player 1 wins!" << endl;
            }
            else{
                 cout << "Player 2 wins!" << endl;
            }
        }
        else if (handOne_rank == 900){
            if (handOne.getHand().at(2)->value > handTwo.getHand().at(2)->value){
                cout << "Player 1 wins!" << endl;
            }
            else{
                 cout << "Player 2 wins!" << endl;
            }
        }
        else if (handOne_rank == 800){
            if (handOne.getHand().at(2)->value > handTwo.getHand().at(2)->value){
                cout << "Player 1 wins!" << endl;
            }
            else{
                 cout << "Player 2 wins!" << endl;
            }
        }
        else if (handOne_rank == 700){
            int i=4;
            while (i >= 0 && handOne.getHand().at(i)->value == handTwo.getHand().at(i)->value){
                i--;
            }
            if (i==-1){
                cout << "Pot is split equally." << endl;
                return;
            }
            int handOneHigh = handOne.getHand().at(i)->value;
            int handTwoHigh = handTwo.getHand().at(i)->value;
            
            if (handOneHigh > handTwoHigh){
                cout << "Player 1 wins!" << endl;
            }
            else if (handOneHigh < handTwoHigh){
                cout << "Player 2 wins!" << endl;
            }
        }
        else if (handOne_rank = 600){
            int i=4;
            while (i >= 0 && handOne.getHand().at(i)->value == handTwo.getHand().at(i)->value){
                i--;
            }
            if (i==-1){
                cout << "Pot is split equally." << endl;
                return;
            }
            int handOneHigh = handOne.getHand().at(i)->value;
            int handTwoHigh = handTwo.getHand().at(i)->value;
            
            if (handOneHigh > handTwoHigh){
                cout << "Player 1 wins!" << endl;
            }
            else if (handOneHigh < handTwoHigh){
                cout << "Player 2 wins!" << endl;
            }
        }
    }
}

int PokerScoreKey::rankHand(Hand& h) {
    string handStr = h.viewHand();
    int handRank = 0;
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

    /*
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
    
    **Deuce-to-seven low rules (A is the highest)
    */
   
    if (isStraightFlush(h) == true){    
        handRank = SFR;
    }
    else if (isFourofaKind(h) == true){
        handRank = FOUR;
    }
    else if (isFullHouse(h) == true){
        handRank = FHR;
    }
    else if (isFlush(h) == true){
        handRank = FR;
    }
    else if (isStraight(h) == true){
        handRank = SR;
    }/*
    else if (isThreeofaKind(h) == true){

    }*/

    return handRank;
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