#include "../header/pokerScoreKey.hpp"

using namespace std;

PokerScoreKey::PokerScoreKey() {}

PokerScoreKey::~PokerScoreKey() {}

void PokerScoreKey::revealHands(Hand& handOne, Hand& handTwo){
    // Get rank for each hand
    int handOne_rank = rankHand(handOne);
    int handTwo_rank = rankHand(handTwo);

    // Compare each hand's rank
    if (handOne_rank > handTwo_rank)
        cout << "Player 1 wins." << endl;
    else if (handOne_rank < handTwo_rank)
        cout << "Player 2 wins." << endl;
    else{
        // Compare straight-flush hands
        if (handOne_rank == 9){
            if (handOne.getHand().at(4)->value > handTwo.getHand().at(4)->value){
                cout << "Player 1 wins!" << endl;
            }
            else{
                 cout << "Player 2 wins!" << endl;
            }
        }
        // Comapre four-of-a-kind hands
        else if (handOne_rank == 8){
            if (handOne.getHand().at(2)->value > handTwo.getHand().at(2)->value){
                cout << "Player 1 wins!" << endl;
            }
            else{
                 cout << "Player 2 wins!" << endl;
            }
        }
        // Compare full-house hands
        else if (handOne_rank == 7){
            if (handOne.getHand().at(2)->value > handTwo.getHand().at(2)->value){
                cout << "Player 1 wins!" << endl;
            }
            else{
                 cout << "Player 2 wins!" << endl;
            }
        }
        // Comapre flush hands
        else if (handOne_rank == 6){
            // Find high card in each hand
            int i=4;
            while (i >= 0 && handOne.getHand().at(i)->value == handTwo.getHand().at(i)->value){
                i--;
            }
            // No high cards means the hands are the same
            if (i==-1){
                cout << "Pot is split equally among flush hands." << endl;
                return;
            }
            int handOneHigh = handOne.getHand().at(i)->value;
            int handTwoHigh = handTwo.getHand().at(i)->value;
            
            // Compare each hand's high card
            if (handOneHigh > handTwoHigh){
                cout << "Player 1 wins!" << endl;
            }
            else if (handOneHigh < handTwoHigh){
                cout << "Player 2 wins!" << endl;
            }
        }
        // Compare straight hands
        else if (handOne_rank == 5){
            // No high cards means the hands are the same and no need for comparing
            if (handOne.getHand().at(4)->value == handTwo.getHand().at(4)->value){
                cout << "Pot is split equally among straight hands." << endl;
                return;
            }

            // Compare each hand's high card
            int handOneHigh = handOne.getHand().at(4)->value;
            int handTwoHigh = handTwo.getHand().at(4)->value;

            if (handOneHigh > handTwoHigh){
                cout << "Player 1 wins!" << endl;
            }
            else if (handOneHigh < handTwoHigh){
                cout << "Player 2 wins!" << endl;
            }
        }
        // Compare three-of-a-kind hands
        else if(handOne_rank == 4){
            // Compare middle cards
            if (handOne.getHand().at(2)->value > handTwo.getHand().at(2)->value){
                cout << "Player 1 wins!" << endl;
            }
            else{
                 cout << "Player 2 wins!" << endl;
            }
        }
        // Compare two-pair hands
        else if (handOne_rank == 3){
            // Compare largest pair
            if (handOne.getHand().at(3)->value > handTwo.getHand().at(3)->value){
                cout << "Player 1 wins!" << endl;
            }
            else if (handOne.getHand().at(3)->value < handTwo.getHand().at(3)->value){
                cout << "Player 2 wins!" << endl;
            }
            else{
                // Compare the next pair
                if (handOne.getHand().at(1)->value > handTwo.getHand().at(1)->value){
                    cout << "Player 1 wins!!" << endl;
                }
                else if (handOne.getHand().at(1)->value < handTwo.getHand().at(1)->value){
                    cout << "Player 2 wins!!" << endl;
                }
                else{
                    // Compare kickers
                    int handOne_kicker, handTwo_kicker;

                    // Find handOne's kicker
                    if (handOne.getHand().at(0)->value==handOne.getHand().at(1)->value && handOne.getHand().at(2)->value==handOne.getHand().at(3)->value){
                        handOne_kicker = handOne.getHand().at(4)->value;
                    }
                    else if (handOne.getHand().at(0)->value==handOne.getHand().at(1)->value && handOne.getHand().at(3)->value==handOne.getHand().at(4)->value){
                        handOne_kicker = handOne.getHand().at(2)->value;
                    }
                    else{
                        handOne_kicker = handOne.getHand().at(0)->value;
                    }

                    // Find handTwo's kicker
                    if (handTwo.getHand().at(0)->value==handTwo.getHand().at(1)->value && handTwo.getHand().at(2)->value==handTwo.getHand().at(3)->value){
                        handTwo_kicker = handOne.getHand().at(4)->value;
                    }
                    else if (handTwo.getHand().at(0)->value==handTwo.getHand().at(1)->value && handTwo.getHand().at(3)->value==handTwo.getHand().at(4)->value){
                        handTwo_kicker = handOne.getHand().at(2)->value;
                    }
                    else{
                        handTwo_kicker = handTwo.getHand().at(0)->value;
                    }

                    // Compare handOne and handTwo kickers
                    if (handOne_kicker > handTwo_kicker){
                        cout << "Player 1 wins!!!" << endl;
                    }
                    else if (handOne_kicker < handTwo_kicker){
                        cout << "Player 2 wins!!!" << endl;
                    }
                    else{
                        cout << "Pot is split equally among two-pairs!" << endl;
                    }
                }
            }
        }
        // Compare pair hands
        else if (handOne_rank == 2){
            int handOne_pair, handTwo_pair;
            
            // Find handOne's pair
            for (int i = 0; i < handOne.getHand().size() - 1; i++) {
                if (handOne.getHand().at(i)->value == handOne.getHand().at(i+1)->value) {
                    handOne_pair = handOne.getHand().at(i)->value;
                }
            }

            // Find handTwo's pair
            for (int i = 0; i < handTwo.getHand().size() - 1; i++) {
                if (handTwo.getHand().at(i)->value == handTwo.getHand().at(i+1)->value) {
                    handTwo_pair = handTwo.getHand().at(i)->value;
                }
            }

            // Compare pairs
            if (handOne_pair > handTwo_pair){
                cout << "Player 1 wins!" << endl;
            }
            else if (handOne_pair < handTwo_pair){
                cout << "Player 2 wins!" << endl;
            }
            else{
                // Compare kickers
                int handOne_kicker, handTwo_kicker;

                // Find handOne's high kicker
                int i=4;
                while (i>=0){
                    if (handOne_pair == handOne.getHand().at(i)->value){
                        i--;
                        continue;
                    }
                    else if (handOne.getHand().at(i)->value > handTwo.getHand().at(i)->value){
                        cout << "Player 1 wins!!" << endl;
                        break;
                    }
                    else if (handOne.getHand().at(i)->value > handTwo.getHand().at(i)->value){
                        cout << "Player 2 wins!!" << endl;
                        break;
                    }
                    i--;
                }

                // Hands have same values
                if (i==-1){
                    cout << "Pot is split equally among pair hands!" << endl;
                }
            }
        }
        // Compare high card hands
        else{
            // Find the highest card in hands
            int i=4;
            while (i>=0){
                if(handOne.getHand().at(i)->value > handTwo.getHand().at(i)->value){
                    cout << "Player 1 wins!" << endl;
                    break;
                }
                else if (handOne.getHand().at(i)->value < handTwo.getHand().at(i)->value){
                    cout << "Player 2 wins!" << endl;
                    break;
                }
                i--;
            }
            // No high card means same values
            if (i==-1)
                cout << "Pot is split equally among high card hands." << endl;
        }
    }
}

int PokerScoreKey::rankHand(Hand& h) {
    string handStr = h.viewHand();
    int handRank = 0;
    // Rank values 
    const int SFR = 9,     
              FOUR = 8,     
              FHR = 7,
              FR = 6,
              SR = 5,
              THREE = 4,
              TWO = 3,
              PAIR = 2,
              HIGH = 1;

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
    }
    else if (isThreeofaKind(h) == true){
        handRank = THREE;
    }
    else if (isTwoPair(h) == true){
        handRank = TWO;
    }
    else if (isPair(h)== true){
        handRank = PAIR;
    }

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
    
    //if (PokerScoreKey::isPair(h)) {
        /* 
        two pair means either 
        - " 'a a b b' c " (valid)
        - " a 'b b c c' " (valid)
        - " a a b c c " (valid) 
        since hand is sorted!!!!
        */

        //we already checked leftmost pair when checking for isPair(), therefore only need to check rightmost pair

        // " 'a a b b' c " (valid)
        /*bool conditionOne = h.getHand().at(2)->value == h.getHand().at(3)->value;

        // " a 'b b c c' " (valid) | " a a b c c " (valid)
        bool conditionTwo = h.getHand().at(3)->value == h.getHand().at(4)->value;

       return (conditionOne || conditionTwo);
    }*/

    
    bool conditionOne = h.getHand().at(0)->value == h.getHand().at(1)->value
                     && h.getHand().at(2)->value == h.getHand().at(3)->value 
                     && h.getHand().at(1)->value != h.getHand().at(2)->value;

    bool conditionTwo = h.getHand().at(0)->value == h.getHand().at(1)->value
                     && h.getHand().at(3)->value == h.getHand().at(4)->value 
                     && h.getHand().at(1)->value != h.getHand().at(3)->value;

    bool conditionThree = h.getHand().at(1)->value == h.getHand().at(2)->value
                     && h.getHand().at(3)->value == h.getHand().at(4)->value 
                     && h.getHand().at(2)->value != h.getHand().at(3)->value;

    if (conditionOne || conditionTwo || conditionThree){
        return true;
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