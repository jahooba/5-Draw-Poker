#pragma once
#include "../header/hand.hpp"

class Deck: public Hand{
    private:
        void generateDeck();
    public:
        Deck();
        Card* distributeRandomCard();
};
