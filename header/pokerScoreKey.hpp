#pragma once

#include <unordered_map>
#include "../header/hand.hpp"
#include "../header/deck.hpp"
#include "../header/player.hpp"
#include "../header/poker.hpp"
#include <vector>


class PokerScoreKey {
    private:
        unordered_map<string, int> scoreKey;

        void generateScoreKey();
        int scoreHand(const Hand&);

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
        unordered_map<string, int>& getScoreKey() {
            return scoreKey;
        }
};