#include "../header/hand.hpp"
#include<iostream>

using namespace std;

Hand::Hand() {

}

Hand::~Hand() {
    Hand::clearHand();
    hand.clear();
}

vector<Card*> Hand::getHand() const {
    return hand;
}


bool Hand::operator==(const Hand& rhs) const {
    vector<Card*> rhsHand = rhs.getHand();

    return Hand::viewHand() == rhs.viewHand();
}

void Hand::obtainCard(Card* card) {

    if (hand.size() < MAX_SIZE) {
        hand.push_back(card);
    }

    Hand::sortHand();

    return;
}

Card* Hand::distributeCard(CardValue v, CardSuit s) {
    Card* temp = nullptr;

    for (int i = 0; i < hand.size(); i++) {
        if (hand.at(i)->value == v && hand.at(i)->suit == s) {
            temp = hand.at(i);
            hand.erase(hand.begin() + i);
            break;
        }
    }
    return temp;
}

Card* Hand::distributeCard(int index) {
    Card* cardToDistribute = hand.at(index);
    return Hand::distributeCard(cardToDistribute->value, cardToDistribute->suit);
}


void Hand::sortHand() {
    if (hand.size() > 1){
        int i, j, tempValue, tempSuit;

        for (i = 1; i < hand.size(); i++){
            tempValue = hand.at(i)->value;
            tempSuit = hand.at(i)->suit;
            j = i - 1;

            while(j >= 0 && hand.at(j)->value >= tempValue){

                if (hand.at(j)->value > tempValue) {
                    swap(hand.at(j+1), hand.at(j));
                }

                else if (hand.at(j)->value == tempValue && hand.at(j)->suit > tempSuit) {
                    swap(hand.at(j+1), hand.at(j));
                }

                j--;
            }
        }
    }
}

string Hand::viewHand() const {
    stringstream ss;
    string suit;
    int i = 0;

    if (hand.empty()) return "Empty!";

    ss << "| ";

    for (i = 0; i < hand.size(); i++) {

        if (hand.at(i) == nullptr) {
            continue;
        }

        else {

            //find suit
            if (hand.at(i)->suit == Clubs) {
                suit = "\u2667";
                ss << suit << " ";
            }

            else if (hand.at(i)->suit == Diamonds) {
                suit = "\u2662";
                ss  << suit << " ";
            }
            
            else if (hand.at(i)->suit == Hearts) {
                suit = "\u2661";
                ss  << suit << " ";
            }

            else if (hand.at(i)->suit == Spades) {
                suit = "\u2664";
                ss << suit << " ";
            }

            //find values
            if (hand.at(i)->value == J) {
                ss << "J" << " ";
            }

            else if (hand.at(i)->value == Q) {
                ss << "Q" << " ";
            }

            else if (hand.at(i)->value == K) {
                ss << "K" << " ";
            }

            else if (hand.at(i)->value == A) {
                ss << "A" << " ";
            }

            else {
                ss << hand.at(i)->value << " ";
            }

            ss << "| " ;
        }
    }
    

    return ss.str();
}

void Hand::clearHand() {
    if (hand.empty()) {
        return;
    }

    for (Card* item : hand) {
        if (item != nullptr) {
            delete item;
        }
    }

    hand.clear();
}
