#include "../header/pokerComputer.hpp"

PokerComputer::PokerComputer() : PokerPlayer("PokerAI", 10000) {
    RANDOM_SEED = 0;
    srand(RANDOM_SEED);
    currMaxBet = 0;

    currAction = new PokerAction(Bet, 0);

}

PokerComputer::PokerComputer(double balance) : PokerPlayer("PokerAI", balance) {
    RANDOM_SEED = 0;
    srand(RANDOM_SEED);
    currMaxBet = 0;

    currAction = new PokerAction(Bet, 0);
}

PokerComputer::PokerComputer(Hand* hand) : PokerPlayer("PokerAI", 10000, hand) {
    RANDOM_SEED = 0;
    srand(RANDOM_SEED);
    currMaxBet = 0;

    currAction = new PokerAction(Bet, 0);
}

PokerComputer::PokerComputer(double balance, Hand* hand) : PokerPlayer("PokerAI", balance, hand) {
    RANDOM_SEED = 0;
    srand(RANDOM_SEED);
    currMaxBet = 0;

    currAction = new PokerAction(Bet, 0);
}

PokerComputer::~PokerComputer() {
    //yay nothing needed i think
}

int PokerComputer::getHandScore() {
    return POKER_SCORE_KEY.rankHand(*hand);
}

PokerAction* PokerComputer::pokerMove() {
    int handScore = PokerComputer::getHandScore();

    int betAmountAdded = 0;
    PokerActionType todoAction = Fold;
    
    if (rand() % 100 == 69) {
        betAmountAdded = balance->getBalance();
        todoAction = Bet;
    }

    else {

        if ((currAction->bet == currMaxBet && currMaxBet > 0) || handScore == 0) {
            if (handScore > 7 || rand() % 100 == 1) {
                todoAction = Bet;
                betAmountAdded = ((rand() % 3 + 1)* handScore << (rand() % 2 + 1)) / 4;
            }

            else {
                todoAction = Check;
            }
        }

        else {
            
            if (handScore > 7) {
                todoAction = Bet;
                betAmountAdded = ((rand() % 25 + 1)* handScore << (rand() % 4 + 1)) / 4;
            }

            else if (handScore > 4 && currMaxBet >= currAction->bet) {
                todoAction = Bet;
                betAmountAdded = currMaxBet - currAction->bet + ((rand() % 10 + 1)* handScore << (rand() % 4 + 1)) / 4;
            }

            else if (handScore > 4) {
                todoAction = Call;
                betAmountAdded = currMaxBet - currAction->bet;
            }

            else {
                if (rand() % 5 == 1) {
                    todoAction = Call;
                    betAmountAdded = currMaxBet - currAction->bet;
                }

                else {
                    todoAction = Fold;
                    betAmountAdded = 0;
                }
            }

        }

    }

    if (currAction->bet + betAmountAdded > absoluteMaxBet) {
        betAmountAdded = absoluteMaxBet - currAction->bet;
    }

    //should only run on lowest bank acc player, due to how currMaxBet works 
    if (betAmountAdded > balance->getBalance()) {
        betAmountAdded = balance->getBalance();
    }

    if (currMaxBet == currAction->bet + betAmountAdded && betAmountAdded > 0) {
        todoAction = Call;
    }
    
    if (betAmountAdded == 0) {
        todoAction = Check;
    }



    balance->appendBalance(betAmountAdded * -1);
    
    this->currAction->type = todoAction;
    this->currAction->bet += betAmountAdded;

    
    return currAction;
}

PokerAction* PokerComputer::pokerMove(double newCurrMaxBet) {
    PokerComputer::setCurrMaxBet(newCurrMaxBet);
    return PokerComputer::pokerMove();
}