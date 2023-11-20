#include "../header/poker.hpp"
using namespace std;

Poker::Poker(vector<Player*> playerList){
    Poker::generateScoreKey();
}

~Poker::Poker() {
    POKER_SCORE_KEY.clear();
}

void Poker::generateScoreKey() {
    POKER_SCORE_KEY = PokerScoreKey().getScoreKey();
}

void Poker::Game_Start(){}

const int Poker::getHandScore(const Hand& h) const {
    string handStr = h.viewHand();

    return POKER_SCORE_KEY.at(handStr);
}

void Poker::payout(Player* player){}
