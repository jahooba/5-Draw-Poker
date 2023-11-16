#pragma once
#include <vector>
#include <unordered_map>
#include <iostream>
#include <sstream>

using namespace std;

enum CardSuit {
    Clubs,
    Spades,
    Diamonds,
    Hearts
};

enum CardValue {
    Two = 2,
    Three = 3,
    Four = 4,
    Five = 5,
    Six = 6,
    Seven = 7,
    Eight = 8,
    Nine = 9,
    Ten = 10,
    J = 11,
    Q = 12,
    K = 13,
    A = 14
};

struct Card {
    CardValue value;
    CardSuit suit;
    Card(CardValue v, CardSuit s) {
        suit = s;
        value = v;
    }
};


class Hand {
    private:
        //sorts the hand from lowest to highest
        const int MAX_SIZE = 5;
    
    protected:
        vector<Card*> hand;
        void sortHand();

    public:

        //default constructor
        Hand();

        //destructor
        ~Hand();

        //assignment operator overload
        bool operator==(const Hand& rhs) const;

        /*
        Appends a card to hand.
        input: card to add
        */
        void obtainCard(Card*);

        /*
        Discards a Card
        input: Card to be discarded
        output: The discarded card
        */
        Card* distributeCard(CardValue, CardSuit);

        //returns string of hand
        string viewHand() const;
        
        //clears out the hand
        void clearHand();

        vector<Card*> getHand() const;

};
