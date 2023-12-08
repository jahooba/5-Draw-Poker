#include "../header/poker.hpp"
#include <algorithm>
using namespace std;

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
    else{
        playerList.at(0)->getPlayerBalance()->appendBalance(-5);
        playerList.at(0)->clearAction();
        playerList.at(1)->getPlayerBalance()->appendBalance(-5);
        pot+=10;
    }

    vector<double> playerBalances;
    playerBalances.push_back(playerList.at(0)->getPlayerBalance()->getBalance());
    cout << "Player 1 balance: " << playerList.at(0)->getPlayerBalance()->getBalance() << endl;
    playerBalances.push_back(playerList.at(1)->getPlayerBalance()->getBalance());
    cout << "Player 2 balance: " << playerList.at(1)->getPlayerBalance()->getBalance() << endl;
    double maxBetForGame = *min_element(playerBalances.begin(), playerBalances.end());
    cout << "Max bet for game = " << maxBetForGame << endl;
    
    //initial player cleansing
    for (PokerPlayer* player : playerList) {
        player->getPlayerHand()->clearHand();
        player->setAbsMaxBet(maxBetForGame);
    }

    //Distribute cards from deck to each player
    for(int i=0; i<5; i++){
        playerList.at(0)->getPlayerHand()->obtainCard(deck.distributeRandomCard());
        playerList.at(1)->getPlayerHand()->obtainCard(deck.distributeRandomCard());
    }

    //Present Poker actions for each player

    double roundMaxBet = 5;
    while (playerList.at(0)->getRecentMove()->bet - roundMaxBet <= 0 and playerList.at(1)->getRecentMove()->bet - roundMaxBet <= 0) {
        
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

    //Present Poker actions for each player
    playerActionRound(playerOneIndex);

    if (playerList.at(0)->getPlayerHand()->viewHand() == "Empty!") {
        revealHands();
        return;
    }

    computerActionRound(playerList.at(1));

    if (playerList.at(1)->getPlayerHand()->viewHand() == "Empty!") {
        revealHands();
        return;
    }

    //Reveal hands for each player and decide winner
    revealHands();
}


void Poker::playerDiscardRound(PokerPlayer* player) {
    cout << endl << player->getPlayerHand()->viewHand() << endl;

    //Prompt player for amount of cards to discard
    cout << "\n\tDISCARD ROUND\nHow many cards will you discard?> ";
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
    cout << endl << playerList.at(playerIndex)->getPlayerHand()->viewHand() << endl;

    PokerAction* previousPlayerMove;
    if(playerIndex==0){
        previousPlayerMove = playerList.at(1)->getRecentMove();
        if(previousPlayerMove==nullptr){
        }
    }
    else{
        previousPlayerMove = playerList.at(0)->getRecentMove();
        if(previousPlayerMove==nullptr){
        }
    }

    int actionChoice=0;
    //Check if previous player's move was not a bet
    if (previousPlayerMove == nullptr || previousPlayerMove->type != Bet){
        cout << "\n\tPOKER ACTION ROUND\n1. Check\n2. Bet\n3. Fold\n > ";
        while (!(cin >> actionChoice) || actionChoice<1 || actionChoice>4){
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Enter valid integer amount (1,2,3)> ";
        }
        if(actionChoice>1)
            actionChoice+=1;
    }
    else{
        if(playerList.at(playerIndex)->getPlayerBalance()->getBalance() <= 0){
            cout << "You can't match bet" << endl;
            actionChoice=4;
        }
        else{
            cout << "\n\tPOKER ACTION ROUND\n1. Call\n2. Bet\n3. Fold\n > ";
            while (!(cin >> actionChoice) || actionChoice<1 || actionChoice>3){
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Enter valid integer (1,2,3)> ";
            }
            actionChoice+=1;
        }       
    }

    switch(actionChoice){
        case 1:
        {
            //Check
            cout << "Checking..." << endl;
            PokerAction* playerCheck = playerList.at(playerIndex)->pokerMove(Check, 0);
        }
            break;
        
        case 2:
        {
            //Call if previous move was a bet
            cout << "Calling..." << previousPlayerMove->bet << endl;
            PokerAction* playerCall = playerList.at(playerIndex)->pokerMove(Call, previousPlayerMove->bet);
        }
            break;
        
        case 3:
        {
            cout << "Betting..." << endl;
            //Bet an amount
            double betAmount;
            if (previousPlayerMove==nullptr){
                //cout << previousPlayerMove->bet << endl;
                cout << "How much would you like to bet? (Bet=0)> $";
                while (!(cin >> betAmount) || betAmount < 0 || betAmount + playerList.at(playerIndex)->getPlayerBalance()->getBalance() > playerList.at(0)->getAbsMaxBet()){
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "Enter valid amount> ";
                }
            }
            else{
                //cout << previousPlayerMove->bet << endl;
                cout << "How much would you like to bet? (Bet=" << previousPlayerMove->bet << ")> $";
                while (!(cin >> betAmount) || betAmount < 0 || betAmount + playerList.at(playerIndex)->getPlayerBalance()->getBalance() > playerList.at(0)->getAbsMaxBet()){
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "Enter valid amount> ";
                }
            }
            PokerAction* playerBet = playerList.at(playerIndex)->pokerMove(Bet, betAmount);
            playerList.at(playerIndex)->setAbsMaxBet(betAmount);
        }
            break;
        
        case 4:
        {
            //Fold by giving up hand

            cout << "Folding..." << endl;
            PokerAction* playerFold = playerList.at(playerIndex)->pokerMove();
            playerList.at(playerIndex)->getPlayerHand()->clearHand();
        }
            break;
        
        default:
            break;
    }
}

void Poker::computerDiscardRound(PokerPlayer* player) {
    if (POKER_SCORE_KEY.rankHand(*player->getPlayerHand()) > 7) {
        //do nothing yay
    }
    
    else if (POKER_SCORE_KEY.rankHand(*player->getPlayerHand()) > 5) {
        int discardPlace=-1;
        while(discardPlace<0 || discardPlace>5)
            discardPlace = rand() % 5;
        cout << discardPlace << endl;
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
        cout << firstDiscardPlace << " " << secondDiscardPlace << " " << thirdDiscardPlace << endl;

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
    vector<double> betAmounts;
    for (PokerPlayer* player : playerList) {
        betAmounts.push_back(player->getRecentMove()->bet);
    }

    double maxBetForRound = *max_element(betAmounts.begin(), betAmounts.end());
    computer->setCurrMaxBet(maxBetForRound);

    PokerAction* computerAction = computer->pokerMove();

    if (computerAction->type == Fold) {
        computer->getPlayerHand()->clearHand();
    }
}

void Poker::revealHands() {
    cout << "\nPlayer 1: " << playerList.at(0)->getPlayerHand()->viewHand() << endl;
    cout << "Player 2: " << playerList.at(1)->getPlayerHand()->viewHand() << endl;

    for (PokerPlayer* player : playerList) {
        player->updateStatistics(0, 1);
    }

        
    int playerOneWins = POKER_SCORE_KEY.winningHand(*playerList.at(0)->getPlayerHand(), *playerList.at(1)->getPlayerHand());
    switch(playerOneWins){
        case 0:
            cout << "Player 2 wins!" << endl;
            winner = playerList.at(1);
            payout();
            break;
        case 1:
            cout << "Player 1 wins!" << endl;
            winner = playerList.at(0);
            payout();
            break;
        default:
            cout << "Pot is coin-flipped." << endl;
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
        cout << currPlayer->getName() << " bet $" << currPlayer->getRecentMove()->bet;
        pot += currPlayer->getRecentMove()->bet;
    }

    winner->getPlayerBalance()->appendBalance(pot);
    cout << "The pot for the round was $" << pot << endl;
}
