#pragma once
#include "hanp.hpp"

class Deck::public Hand{
        private:
                void generateDeck();
        public:
                Deck();
                distributeRandomCard();
};
