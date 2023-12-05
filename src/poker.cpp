#include "../header/poker.hpp"
using namespace std;

Poker::Poker(vector<PokerPlayer*> playerList){
    
}

Poker::~Poker() {
    //POKER_SCORE_KEY.clear();
}



void Poker::Game_Start(){}

const int Poker::getHandScore(const Hand& h) const {
    return POKER_SCORE_KEY.rankHand(h);
}

void Poker::payout() {
    
    for (PokerPlayer* currPlayer : playerList) {
        pot += currPlayer->getRecentMove()->bet;
    }

    winner->getBalance()->appendBalance(pot); 
}
