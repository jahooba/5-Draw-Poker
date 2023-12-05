#include "../header/poker.hpp"
using namespace std;

Poker::Poker() {
    
}


Poker::~Poker() {
    winner = nullptr;
    playerList.clear();
}


void Poker::Game_Start() {}

const int Poker::getHandScore(const Hand& h) const {
    return POKER_SCORE_KEY.rankHand(h);
}

void Poker::payout() {
    
    for (PokerPlayer* currPlayer : playerList) {
        pot += currPlayer->getRecentMove()->bet;
    }

    winner->getBalance()->appendBalance(pot);
}
