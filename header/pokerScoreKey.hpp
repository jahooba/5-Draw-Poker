#pragma once

#include "../header/hand.hpp"

class PokerScoreKey {
    private:

        bool isHighCard(const Hand&);
        bool isPair(const Hand&);
        bool isTwoPair(const Hand&);
        bool isThreeofaKind(const Hand&);
        bool isStraight(const Hand&);
        bool isFlush(const Hand&);
        bool isFullHouse(const Hand&);
        bool isFourofaKind(const Hand&);
        bool isStraightFlush(const Hand&);

    public:
        PokerScoreKey();
        ~PokerScoreKey();
        int rankHand(const Hand&);
        int winningHand(Hand&, Hand&);

};