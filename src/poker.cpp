#include "../header/poker.hpp"
using namespace std;

Poker::Poker(vector<Player*> playerList){
    this->playerList = playerList;
}

Poker::~Poker() {
    //POKER_SCORE_KEY.clear();
}



void Poker::Game_Start(){}

void Poker::revealHands(){
    Hand* handOne_ptr, handTwo_ptr;
    handOne_ptr = playerList.at(0)->getPlayerHand();
    handTwo_ptr = playerList.at(1)->getPlayerHand();
    // Get rank for each hand
    int handOne_rank = KEY.rankHand(handOne_ptr);
    int handTwo_rank = KEY.rankHand(handTwo_ptr);

    // Compare each hand's rank
    if (handOne_rank > handTwo_rank)
        cout << "Player 1 wins." << endl;
    else if (handOne_rank < handTwo_rank)
        cout << "Player 2 wins." << endl;
    else{
        // Compare straight-flush hands
        if (handOne_rank == 9){
            if (handOne_ptr->getHand().at(4)->value > handTwo_ptr.getHand().at(4)->value){
                cout << "Player 1 wins!" << endl;
            }
            else{
                 cout << "Player 2 wins!" << endl;
            }
        }
        // Comapre four-of-a-kind hands
        /*else if (handOne_rank == 8){
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
        }*/
    }
}

/*const int Poker::getHandScore(const Hand& h) const {
    string handStr = h.viewHand();

    return POKER_SCORE_KEY.at(handStr);
}*/

void Poker::payout(Player* player){}
