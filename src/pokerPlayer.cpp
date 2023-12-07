#include "../header/statistics.hpp"  
#include "../header/player.hpp" 
#include "../header/balance.hpp"  
#include "../header/pokerPlayer.hpp"   


PokerPlayer::PokerPlayer() : Player() {
    pokerStats = Statistics(name);
}

PokerPlayer::PokerPlayer(string name) : Player(name) {
    pokerStats = Statistics(name);
}

PokerPlayer::PokerPlayer(string name, double balance) : Player(name, balance) {
    pokerStats = Statistics(name);
}

PokerPlayer::PokerPlayer(string name, double balance, Hand* hand) : Player(name, balance, hand) {
    pokerStats = Statistics(name);
}

PokerPlayer::~PokerPlayer() {

    if (currAction == nullptr) {
        currAction = new PokerAction(Bet, 0);
    }

    delete currAction;
}

void PokerPlayer::updateStatistics(int gamesWon, int gamesPlayed){
    pokerStats.update(gamesWon, gamesPlayed);
}

void PokerPlayer::viewStatistics() {
    pokerStats.print();
}

PokerAction* PokerPlayer::pokerMove() {
    PokerActionType action = Bet;
    double bet = 0;

    if (currAction == nullptr) {
        currAction = new PokerAction(action, bet);
    }

    else {
        this->currAction->type = action;
        this->currAction->bet = bet;
    }

    return currAction;
}


PokerAction* PokerPlayer::pokerMove(PokerActionType action, double bet) {
    balance->appendBalance(bet * -1);
    
    if (currAction == nullptr) {
        PokerAction* newAction = new PokerAction(action, bet);
        currAction = newAction;
    }

    else {
        this->currAction->type = action;
        this->currAction->bet += bet;
    }

    return currAction;
}
