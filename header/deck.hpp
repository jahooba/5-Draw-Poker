#pragma once
#include "../header/hand.hpp"
#include <ctime>

class Deck: public Hand {
    private:
        const int MAX_SIZE = 52;
        void generateDeck();
    public:
        Deck();
        ~Deck();

        /*
        Appends a card to deck.
        input: card to add
        */
        virtual void obtainCard(Card*) override;

        //distributes a randomCard from the deck, and removes it from the deck.
        Card* distributeRandomCard();

        //clears deck and regenerates it
        void reset();
};
