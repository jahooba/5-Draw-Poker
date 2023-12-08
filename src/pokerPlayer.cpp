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

void PokerPlayer::viewBalance() {
    balance->print();
}

PokerAction* PokerPlayer::pokerMove() {
    PokerActionType action = Bet;
    double bet = 0;

    if (currAction == nullptr) {
        currAction = new PokerAction(action, bet);
    }

    this->currAction->type = action;
    this->currAction->bet = bet;

    return currAction;
}

PokerAction* PokerPlayer::pokerMove(PokerActionType action, double betAmountAdded) {
    PokerActionType todoAction = action;
    
    if (currAction == nullptr) {
        currAction = new PokerAction(Fold, 0);
    }
    
    //financial code

    if (currAction->bet + betAmountAdded > absoluteMaxBet) {
        betAmountAdded = absoluteMaxBet - currAction->bet;
    }

    //should only run on lowest bank acc player, due to how absoluteMaxBet works 
    if (betAmountAdded > balance->getBalance()) {
        betAmountAdded = balance->getBalance();
    }

    if (currMaxBet == currAction->bet + betAmountAdded) {
        todoAction = Call;
    }
    
    if (betAmountAdded == 0) {
        todoAction = Check;
    }

    balance->appendBalance(betAmountAdded * -1);
    
    //gameplay code
    this->currAction->type = todoAction;
    this->currAction->bet += betAmountAdded;

    return currAction;
}

void PokerPlayer::clearAction() {
    if (currAction == nullptr) {
        currAction = new PokerAction(Fold, 0);
    }

    delete currAction;
    currAction = nullptr;
}