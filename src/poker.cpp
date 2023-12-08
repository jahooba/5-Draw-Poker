#include "../header/poker.hpp"
#include <algorithm>
using namespace std;

#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"

Poker::Poker() {
    //default
}

Poker::Poker(vector<PokerPlayer*> playerList){
    this->playerList = playerList;
}

Poker::~Poker() {
    winner = nullptr;
    playerList.clear();
}

void Poker::Game_Start(){
    int playerOneIndex = 0, playerTwoIndex = 1;
    double balance = playerList.at(0)->getPlayerBalance()->getBalance();

    //While the player has enough money and wants to play or only one player left
    deck.reset();
    if(balance <= 5){
        cout << "Sorry, you don't have enough money to play :(" << endl;
        return;
    }

    vector<double> playerBalances;
    playerBalances.push_back(playerList.at(0)->getPlayerBalance()->getBalance());
    cout << GREEN << "Player 1 " << RESET  << "balance: " << playerList.at(0)->getPlayerBalance()->getBalance() << endl;
    playerBalances.push_back(playerList.at(1)->getPlayerBalance()->getBalance());
    cout << BLUE << "Player 2" << RESET << " balance: " << playerList.at(1)->getPlayerBalance()->getBalance() << endl;
    double maxBetForGame = *min_element(playerBalances.begin(), playerBalances.end());
    cout << "Max bet for game = " << maxBetForGame << endl << endl;
    
    //initial player cleansing
    for (PokerPlayer* player : playerList) {
        player->clearAction();
        player->setCurrMaxBet(0);
        player->setAbsMaxBet(1000000000000000000);
        player->pokerMove(Call, 5);
        player->getPlayerHand()->clearHand();
        player->setAbsMaxBet(maxBetForGame);
        player->setCurrMaxBet(5);
    }

    //Distribute cards from deck to each player
    for(int i=0; i<5; i++){
        playerList.at(0)->getPlayerHand()->obtainCard(deck.distributeRandomCard());
        playerList.at(1)->getPlayerHand()->obtainCard(deck.distributeRandomCard());
    }

    //Present Poker actions for each player

    double roundMaxBet = 5;

    while ((playerList.at(1)->getRecentMove()->type != Check) || (playerList.at(0)->getRecentMove()->type != Check)) {

        cout << "Current Round:" << endl;
        cout << GREEN << playerList.at(0)->getName()<< RESET << " is betting $" << playerList.at(0)->getRecentMove()->bet << endl;
        cout << BLUE << playerList.at(1)->getName() << RESET << " is betting $" << playerList.at(1)->getRecentMove()->bet << endl;
        
        playerActionRound(playerOneIndex);

        if (playerList.at(0)->getPlayerHand()->viewHand() == "Empty!") {
            revealHands();
            return;
        }

        if (playerList.at(0)->getRecentMove()->bet > roundMaxBet) {
            roundMaxBet = playerList.at(0)->getRecentMove()->bet;

            for (PokerPlayer* player : playerList) {
                player->setCurrMaxBet(roundMaxBet);
            }

        }

        computerActionRound(playerList.at(1));

        if (playerList.at(1)->getPlayerHand()->viewHand() == "Empty!") {
            revealHands();
            return;
        }

        if (playerList.at(1)->getRecentMove()->bet > roundMaxBet) {
            roundMaxBet = playerList.at(1)->getRecentMove()->bet;

            for (PokerPlayer* player : playerList) {
                player->setCurrMaxBet(roundMaxBet);
            }

        }
    }

    //Discard and draw for each player
    playerDiscardRound(playerList.at(0));
    computerDiscardRound(playerList.at(1));

    playerList.at(0)->getRecentMove()->type = Call;
    playerList.at(1)->getRecentMove()->type = Call;

    while ((playerList.at(1)->getRecentMove()->type != Check) || (playerList.at(0)->getRecentMove()->type != Check)) {

        cout << "Current Round:" << endl;
        cout << GREEN << playerList.at(0)->getName() << RESET  <<  " is betting $" << playerList.at(0)->getRecentMove()->bet << endl ;
        cout << BLUE << playerList.at(1)->getName() << RESET << " is betting $" << playerList.at(1)->getRecentMove()->bet << endl;
        
        playerActionRound(playerOneIndex);

        if (playerList.at(0)->getPlayerHand()->viewHand() == "Empty!") {
            revealHands();
            return;
        }

        if (playerList.at(0)->getRecentMove()->bet > roundMaxBet) {
            roundMaxBet = playerList.at(0)->getRecentMove()->bet;

            for (PokerPlayer* player : playerList) {
                player->setCurrMaxBet(roundMaxBet);
            }

        }

        computerActionRound(playerList.at(1));

        if (playerList.at(1)->getPlayerHand()->viewHand() == "Empty!") {
            revealHands();
            return;
        }

        if (playerList.at(1)->getRecentMove()->bet > roundMaxBet) {
            roundMaxBet = playerList.at(1)->getRecentMove()->bet;

            for (PokerPlayer* player : playerList) {
                player->setCurrMaxBet(roundMaxBet);
            }

        }
    }

    //Reveal hands for each player and decide winner
    revealHands();
}


void Poker::playerDiscardRound(PokerPlayer* player) {
    cout << endl << player->getPlayerHand()->viewHand() << endl;

    //Prompt player for amount of cards to discard
    cout << YELLOW << "\n\tDISCARD ROUND" << RESET << "\nHow many cards will you discard?> ";
    int discardAmount=-1;
    //Validate user input is an int between 0 and 3
    while (!(cin >> discardAmount) || discardAmount<0 || discardAmount>3){
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Enter valid integer amount (0,1,2,3)> ";
    }

    switch(discardAmount){
        case 1:
        {
            //Display guide for choosing card
            cout << "\n| 1st card = 1 | 2nd card = 2 | 3rd card= 3 | 4th card = 4 | 5th card = 5 |\n\n";
            cout << "Select the card to discard> ";
            int discardPlace=0;
            //Validate user input is an int between 1 and 5
            while (!(cin >> discardPlace) || discardPlace<1 || discardPlace>5){
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Enter valid integer amount (1,2,3,4,5)> ";
            }

            //Deck obtains the discarded card
            deck.obtainCard(player->getPlayerHand()->distributeCard(discardPlace-1));

            //Player receives random card from deck
            player->getPlayerHand()->obtainCard(deck.distributeRandomCard());
        } 
            break;
        
        case 2:
        {
            cout << "\n| 1st card = 1 | 2nd card = 2 | 3rd card= 3 | 4th card = 4 | 5th card = 5 |\n\n";
            cout << "Select the first card to discard> ";
            int firstDiscardPlace=0;
            while (!(cin >> firstDiscardPlace) || firstDiscardPlace<1 || firstDiscardPlace>5){
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Enter valid integer amount (1,2,3,4,5)> ";
            }
            Card* firstCardToDiscard = player->getPlayerHand()->getHand().at(firstDiscardPlace-1);
            cout << "Select the second card to discard> ";
            int secondDiscardPlace=0;
            while (!(cin >> secondDiscardPlace) || secondDiscardPlace<1 || secondDiscardPlace>5 || secondDiscardPlace==firstDiscardPlace){
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Enter valid integer amount (1,2,3,4,5)> ";
            }
            Card* secondCardToDiscard = player->getPlayerHand()->getHand().at(secondDiscardPlace-1);
            deck.obtainCard(player->getPlayerHand()->distributeCard(firstCardToDiscard->value, firstCardToDiscard->suit));
            deck.obtainCard(player->getPlayerHand()->distributeCard(secondCardToDiscard->value, secondCardToDiscard->suit));
            player->getPlayerHand()->obtainCard(deck.distributeRandomCard());
            player->getPlayerHand()->obtainCard(deck.distributeRandomCard());
        }
            break;

        case 3:
        {
            cout << "\n| 1st card = 1 | 2nd card = 2 | 3rd card= 3 | 4th card = 4 | 5th card = 5 |\n\n";
            cout << "Select the first card to discard> ";
            int firstDiscardPlace=0;
            while (!(cin >> firstDiscardPlace) || firstDiscardPlace<1 || firstDiscardPlace>5){
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Enter valid integer amount (1,2,3,4,5)> ";
            }
            Card* firstCardToDiscard = player->getPlayerHand()->getHand().at(firstDiscardPlace-1);
            cout << "Select the second card to discard> ";
            int secondDiscardPlace=0;
            while (!(cin >> secondDiscardPlace) || secondDiscardPlace<1 || secondDiscardPlace>5 || secondDiscardPlace==firstDiscardPlace){
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Enter valid integer amount (1,2,3,4,5)> ";
            }
            Card* secondCardToDiscard = player->getPlayerHand()->getHand().at(secondDiscardPlace-1);
            cout << "Select the third card to discard> ";
            int thirdDiscardPlace=0;
            while (!(cin >> thirdDiscardPlace) || thirdDiscardPlace<1 || thirdDiscardPlace>5 || thirdDiscardPlace==secondDiscardPlace || thirdDiscardPlace==firstDiscardPlace){
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Enter valid integer amount (1,2,3,4,5)> ";
            }
            Card* thirdCardToDiscard = player->getPlayerHand()->getHand().at(thirdDiscardPlace-1);
            deck.obtainCard(player->getPlayerHand()->distributeCard(firstCardToDiscard->value, firstCardToDiscard->suit));
            deck.obtainCard(player->getPlayerHand()->distributeCard(secondCardToDiscard->value, secondCardToDiscard->suit));
            deck.obtainCard(player->getPlayerHand()->distributeCard(thirdCardToDiscard->value, thirdCardToDiscard->suit));
            player->getPlayerHand()->obtainCard(deck.distributeRandomCard());
            player->getPlayerHand()->obtainCard(deck.distributeRandomCard());
            player->getPlayerHand()->obtainCard(deck.distributeRandomCard());
        }
            break;

        default:
            break;
    }
}

void Poker::playerActionRound(int playerIndex){
    double betAmount = 0;
    PokerActionType todoAction = Call;

    PokerPlayer* player = playerList.at(playerIndex);

    cout << endl << player->getPlayerHand()->viewHand() << endl;

    PokerAction* previousPlayerMove;
    if (playerIndex==0) {
        previousPlayerMove = playerList.at(1)->getRecentMove();
    }
    else {
        previousPlayerMove = playerList.at(0)->getRecentMove();
    }

    int actionChoice = 0;

    //Check if previous player's move was not a bet
    if (previousPlayerMove == nullptr || previousPlayerMove->type != Bet){
        cout << YELLOW << "\n\tPOKER ACTION ROUND" << RESET << "\n1. Check\n2. Bet\n3. Fold\n > ";
        while (!(cin >> actionChoice) || actionChoice < 1 || actionChoice > 3){
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Enter valid integer amount (1,2,3)> ";
        }
        if(actionChoice > 1)
            actionChoice += 1;
    }
    else{
        if(playerList.at(playerIndex)->getPlayerBalance()->getBalance() <= 0){
            cout << "You can't match bet" << endl;
            actionChoice = 4;
        }
        else{
            cout << YELLOW << "\n\tPOKER ACTION ROUND" << RESET << "\n1. Call\n2. Bet\n3. Fold\n > ";
            while (!(cin >> actionChoice) || actionChoice < 1 || actionChoice > 3){
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Enter valid integer (1,2,3)> ";
            }
            actionChoice+=1;
        }       
    }

    if (actionChoice == 1) {
        cout << "Checking..." << endl;
        todoAction = Check;
        betAmount = 0;
    }

    else if (actionChoice == 2) {
        cout << "Calling..." << endl;
        todoAction = Call;
        betAmount = player->getCurrMaxBet() - player->getRecentMove()->bet;
    }

    else if (actionChoice == 3) {
        
        double userInputBet = 0;

        cout << "Betting...";

        cout << "Enter an amount to ADD to the existing bet. Current Bet: $" << player->getCurrMaxBet() << "\n > " << endl;
        while ( !(cin >> userInputBet) || userInputBet > player->getPlayerBalance()->getBalance() || userInputBet < 0) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            
            if (userInputBet <= 0) {
                cout << "Bet Amount is negative! Try again..." << endl;
            }

            else if (userInputBet > player->getPlayerBalance()->getBalance()) {
                cout << "You cannot afford this bet! Try again..." << endl;
            }

            cout << "Enter valid amount: Current Bet: $" << player->getCurrMaxBet() << "\n > " << endl;
        }

        betAmount = userInputBet;
    }

    else {
        cout << "Folding...Better luck next time!";
        todoAction = Fold;
        betAmount = 0;
        player->pokerMove(Fold, 0);
        player->getPlayerHand()->clearHand();
    }

    //edge cases
    if (player->getRecentMove()->bet + betAmount > player->getAbsMaxBet()) {
        betAmount = player->getAbsMaxBet() - player->getRecentMove()->bet;
        cout << "Adjusted bet amount due to going over the limit for the game." << endl;
        cout << "Your new betAmount is $" << player->getAbsMaxBet() << endl;
    }

    if (player->getCurrMaxBet() - (player->getRecentMove()->bet + betAmount) > 0.01 || player->getCurrMaxBet() - (player->getRecentMove()->bet + betAmount) < 0.01) {

        if (player->getRecentMove()->type != Call) {
            todoAction = Call;
            cout << "Action meets the criteria for Call! Changing Action type..." << endl;
        }
    }

    if (betAmount == 0 && todoAction != Check) {
        todoAction = Check;
        cout << "Action meets the criteria for Check! Changing Action type..." << endl;
    }

    player->pokerMove(todoAction, betAmount);
    
}

void Poker::computerDiscardRound(PokerPlayer* player) {
    if (POKER_SCORE_KEY.rankHand(*player->getPlayerHand()) > 7) {
        //do nothing yay
    }
    
    else if (POKER_SCORE_KEY.rankHand(*player->getPlayerHand()) > 5) {
        int discardPlace=-1;
        while(discardPlace<0 || discardPlace>5)
            discardPlace = rand() % 5;
        cout << endl << discardPlace << endl;
        //Deck obtains the discarded card
        deck.obtainCard(player->getPlayerHand()->distributeCard(discardPlace));

        //Player receives random card from deck
        player->getPlayerHand()->obtainCard(deck.distributeRandomCard());
    }

    else {
        int firstDiscardPlace=-1, secondDiscardPlace=-1, thirdDiscardPlace=-1;
        while(firstDiscardPlace<0 || firstDiscardPlace>5)
            firstDiscardPlace = rand() % 5;
        Card* firstCardToDiscard = player->getPlayerHand()->getHand().at(firstDiscardPlace);
        while(secondDiscardPlace<0 || secondDiscardPlace>5 || secondDiscardPlace==firstDiscardPlace)
            secondDiscardPlace = rand() % 5;
        Card* secondCardToDiscard = player->getPlayerHand()->getHand().at(secondDiscardPlace);
        while(thirdDiscardPlace<0 || thirdDiscardPlace>5 || thirdDiscardPlace==secondDiscardPlace || thirdDiscardPlace==firstDiscardPlace)
            thirdDiscardPlace = rand() % 5;
        Card* thirdCardToDiscard = player->getPlayerHand()->getHand().at(thirdDiscardPlace);
        cout << endl << firstDiscardPlace << " " << secondDiscardPlace << " " << thirdDiscardPlace << endl;

        deck.obtainCard(player->getPlayerHand()->distributeCard(firstCardToDiscard->value, firstCardToDiscard->suit));
        deck.obtainCard(player->getPlayerHand()->distributeCard(secondCardToDiscard->value, secondCardToDiscard->suit));
        deck.obtainCard(player->getPlayerHand()->distributeCard(thirdCardToDiscard->value, thirdCardToDiscard->suit));
        player->getPlayerHand()->obtainCard(deck.distributeRandomCard());
        player->getPlayerHand()->obtainCard(deck.distributeRandomCard());
        player->getPlayerHand()->obtainCard(deck.distributeRandomCard());
    }
    
    return;
}

void Poker::computerActionRound(PokerPlayer* computer) {
    PokerAction* computerAction = computer->pokerMove();

    if (computerAction->type == Fold) {
        computer->getPlayerHand()->clearHand();
    }
}

void Poker::revealHands() {
    cout << GREEN << "\nPlayer 1: " << RESET << playerList.at(0)->getPlayerHand()->viewHand() << endl;
    cout << BLUE << "Player 2: " << RESET << playerList.at(1)->getPlayerHand()->viewHand()  << endl;

    for (PokerPlayer* player : playerList) {
        player->updateStatistics(0, 1);
    }

        
    int playerOneWins = POKER_SCORE_KEY.winningHand(*playerList.at(0)->getPlayerHand(), *playerList.at(1)->getPlayerHand());
    switch(playerOneWins){
        case 0:
            cout << BLUE << "Player 2 " << RESET << "wins!" << endl << endl;
            winner = playerList.at(1);
            payout();
            break;
        case 1:
            cout << GREEN <<  "Player 1" << RESET << " wins!" << endl << endl;
            winner = playerList.at(0);
            payout();
            break;
        default:
            cout << "Pot is coin-flipped." << endl << endl << endl;
            int coinFlip = rand() % 2;
            winner = playerList.at(coinFlip);
            payout();
            break;
    }

    winner->updateStatistics(1, 0);
}

const int Poker::getHandScore(const Hand& h) {
    return POKER_SCORE_KEY.rankHand(h);
}

void Poker::payout() {
    
    for (PokerPlayer* currPlayer : playerList) {
        if(currPlayer->getRecentMove()==nullptr)
            return;
        cout << GREEN << currPlayer->getName() << RESET << " bet $" << currPlayer->getRecentMove()->bet << endl;
        pot += currPlayer->getRecentMove()->bet;
    }

    winner->getPlayerBalance()->appendBalance(pot);
    cout << "The pot for the round was $" << pot << endl << endl << endl;
}
