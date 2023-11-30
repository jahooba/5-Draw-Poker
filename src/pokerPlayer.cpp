#include "../header/statistics.hpp"  
#include "../header/player.hpp" 
#include "../header/balance.hpp"  
#include "../header/pokerPlayer.hpp"   


//PokerPlayer::PokerPlayer() = default;

PokerPlayer::PokerPlayer(string name):Player(name){
    Player::Player(name);
    pokerStats = Statistics("usernameStats.txt", name);
}

PokerPlayer::PokerPlayer(string name, double balance):Player(name, balance){
    Player::Player(name, balance);
    pokerStats = Statistics("usernameStats.txt", name);
}

PokerPlayer::~PokerPlayer() {
    Player::~Player();

    if (currAction == nullptr) {
        currAction = new PokerAction(Fold, 0);
    }

    delete currAction;
}

void PokerPlayer::updateStatistics(int gamesWon, int gamesPlayed){
    pokerStats.update(gamesWon, gamesPlayed);
}

void PokerPlayer::viewStatistics(){
    pokerStats.print();
}

PokerAction* PokerPlayer::pokerMove() {
    PokerAction* newAction = new PokerAction(Fold, 0);
    currAction = newAction;

    return currAction;
}

PokerAction* PokerPlayer::pokerMove(PokerActionType action, double bet) {
    PokerAction* newAction = new PokerAction(action, bet);
    currAction = newAction;

    return currAction;
}

