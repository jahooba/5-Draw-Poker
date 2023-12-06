#include "../header/statistics.hpp"  
#include "../header/player.hpp" 
#include "../header/balance.hpp"  
#include "../header/pokerPlayer.hpp"   


//PokerPlayer::PokerPlayer() = default;

PokerPlayer::PokerPlayer(string name) : Player(name) {
    pokerStats = Statistics(name);
}

PokerPlayer::PokerPlayer(string name, double balance) : Player(name, balance) {
    pokerStats = Statistics(name);
}

PokerPlayer::~PokerPlayer() {

    if (currAction == nullptr) {
        currAction = new PokerAction(Fold, 0);
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
    return pokerMove(Fold, 0);
}

PokerAction* PokerPlayer::pokerMove(PokerActionType action, double bet) {
    if (currAction == nullptr) {
        PokerAction* newAction = new PokerAction(action, bet);
        currAction = newAction;
    }

    else {
        this->currAction->type = action;
        this->currAction->bet += bet;
    }

    balance->appendBalance(bet * -1);

    return currAction;
}
