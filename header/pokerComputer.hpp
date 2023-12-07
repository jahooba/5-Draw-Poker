#pragma once

#include "../header/pokerPlayer.hpp"
#include "../header/pokerScoreKey.hpp"
#include <cstdlib>

using namespace std;


class PokerComputer: public PokerPlayer {

    protected: 
        int RANDOM_SEED;
        PokerScoreKey POKER_SCORE_KEY;

    public:
        PokerComputer();
        PokerComputer(double balance);
        PokerComputer(Hand* hand);
        PokerComputer(double balance, Hand* hand);
        ~PokerComputer();
        virtual PokerAction* pokerMove() override;
        PokerAction* pokerMove(double newMaxBet);
        int getHandScore();
};