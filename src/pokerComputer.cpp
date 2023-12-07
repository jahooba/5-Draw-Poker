#include "../header/pokerComputer.hpp"

PokerComputer::PokerComputer() : PokerPlayer("PokerAI", 10000) {
    RANDOM_SEED = 0;
    srand(RANDOM_SEED);
}

PokerComputer::PokerComputer(double balance) : PokerPlayer("PokerAI", balance) {
    RANDOM_SEED = 0;
    srand(RANDOM_SEED);
}

PokerAction* PokerComputer::pokerMove() {
    int handScore = POKER_SCORE_KEY.rankHand(*hand);
    int betAmount = 0;
    
    if (rand() % 100 == 69) {
        betAmount = balance->getBalance();
    }

    else {
        
    }

    balance->appendBalance(bet * -1);
    return nullptr;
}