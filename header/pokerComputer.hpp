#pragma once

#include "../header/pokerPlayer.hpp"
#include "../header/pokerScoreKey.hpp"
#include <cstdlib>

using namespace std;


class PokerComputer: public PokerPlayer {

    private: 
        int RANDOM_SEED;
        PokerScoreKey POKER_SCORE_KEY;
        
        int rankHand();

    public:
        PokerComputer();
        PokerComputer(double);
        virtual PokerAction* pokerMove() override;
};