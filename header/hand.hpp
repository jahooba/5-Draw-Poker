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

// struct HandHasher {
//     size_t operator()(const Hand& h) const {
//         using std::size_t;
//         using std::hash;
//         using std::string;

//         handDupe = h.getHand();

//         return ((hash<string>()(k.first) ^ (hash<string>()(k.second) << 1)) >> 1) ^ (hash<int>()(k.third) << 1);
//     }
// };


class Hand {
    private:
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
        virtual void obtainCard(Card*);

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

        //returns the entire hand.
        vector<Card*> getHand() const;

};
