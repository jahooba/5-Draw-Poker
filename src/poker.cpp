#include "../header/poker.hpp"
using namespace std;

Poker::Poker(vector<Player*> playerList){
    this->playerList = playerList;
}

Poker::~Poker() {
    if (playerList.empty()) {
        return;
    }

    for (Player* item : playerList) {
        if (item != nullptr) {
            delete item;
        }
    }
    playerList.clear();
}



void Poker::Game_Start(){
    bool playAgain = true;
    double balance = playerList.at(0)->getBalance()->getBalance();

    if(balance<=0){
        cout << "Sorry, you don't have enough credits to play :(" << endl;
        return;
    }
    
    //While the player has enough money and wants to play or only one player left
    while (balance > 0 && playAgain == true && playerList.size() > 1){
        //Distribute cards from deck to each player
        for(int i=0; i<5; i++){
            playerList.at(0)->getPlayerHand()->obtainCard(deck.distributeRandomCard());
            playerList.at(1)->getPlayerHand()->obtainCard(deck.distributeRandomCard());
        }
        cout << playerList.at(0)->getPlayerHand()->viewHand() << endl;

        //Present Poker actions for each player

        //Discard and draw for each player
        discardRound();

        //Present Poker actions for each player

        //Reveal hands for each player and decide winner
        cout << endl << playerList.at(0)->getPlayerHand()->viewHand() << endl;
        cout << playerList.at(1)->getPlayerHand()->viewHand() << endl;
        
        //If player has enough credits, prompt user with menu
        if (balance>0){
            cout << "1. Play again\n2.Return to Menu\n>";
            int choice=0;
            while (!(cin >> choice) || choice<0 || choice>2){
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Enter valid integer amount (1-2)> ";
            }
            if (choice==2){
                playAgain = false;
            }
        }
        
    }
}

void Poker::discardRound(){
    //Prompt player for amount of cards to discard
    cout << "\n\tDISCARD ROUND\nHow many cards will you discard? (0-3)> ";
    int discardAmount=-1;
    //Validate user input is an int between 0 and 3
    while (!(cin >> discardAmount) || discardAmount<0 || discardAmount>3){
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Enter valid integer amount (0-3)> ";
    }

    // low priority - for loop instead of if statements
    if (discardAmount==1){
        //Display guide for choosing card
        cout << "\n| 1st card = 1 | 2nd card = 2 | 3rd card= 3 | 4th card = 4 | 5th card = 5 |\n\n";
        cout << "Select the card to discard (1-5)> ";
        int discardPlace=0;
        //Validate user input is an int between 1 and 5
        while (!(cin >> discardPlace) || discardPlace<1 || discardPlace>5){
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Enter valid integer amount (1-5)> ";
        }

        //Deck obtains the discarded card
        deck.obtainCard(playerList.at(0)->getPlayerHand()->distributeCard(discardPlace-1));

        //Player receives random card from deck
        playerList.at(0)->getPlayerHand()->obtainCard(deck.distributeRandomCard());
    }
    else if (discardAmount==2){
        cout << "\n| 1st card = 1 | 2nd card = 2 | 3rd card= 3 | 4th card = 4 | 5th card = 5 |\n\n";
        cout << "Select the first card to discard (1-5)> ";
        int firstDiscardPlace=0;
        while (!(cin >> firstDiscardPlace) || firstDiscardPlace<1 || firstDiscardPlace>5){
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Enter valid integer amount (1-5)> ";
        }
        Card* firstCardToDiscard = playerList.at(0)->getPlayerHand()->getHand().at(firstDiscardPlace-1);

        cout << "Select the second card to discard (1-5)> ";
        int secondDiscardPlace=0;
        while (!(cin >> secondDiscardPlace) || secondDiscardPlace<1 || secondDiscardPlace>5 || secondDiscardPlace==firstDiscardPlace){
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Enter valid integer amount (1-5)> ";
        }
        Card* secondCardToDiscard = playerList.at(0)->getPlayerHand()->getHand().at(secondDiscardPlace-1);

        deck.obtainCard(playerList.at(0)->getPlayerHand()->distributeCard(firstCardToDiscard->value, firstCardToDiscard->suit));
        deck.obtainCard(playerList.at(0)->getPlayerHand()->distributeCard(secondCardToDiscard->value, secondCardToDiscard->suit));

        playerList.at(0)->getPlayerHand()->obtainCard(deck.distributeRandomCard());
        playerList.at(0)->getPlayerHand()->obtainCard(deck.distributeRandomCard());
    }
    else if (discardAmount==3){
        cout << "\n| 1st card = 1 | 2nd card = 2 | 3rd card= 3 | 4th card = 4 | 5th card = 5 |\n\n";
        cout << "Select the first card to discard (1-5)> ";
        int firstDiscardPlace=0;
        while (!(cin >> firstDiscardPlace) || firstDiscardPlace<1 || firstDiscardPlace>5){
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Enter valid integer amount (1-5)> ";
        }
        Card* firstCardToDiscard = playerList.at(0)->getPlayerHand()->getHand().at(firstDiscardPlace-1);

        cout << "Select the second card to discard (1-5)> ";
        int secondDiscardPlace=0;
        while (!(cin >> secondDiscardPlace) || secondDiscardPlace<1 || secondDiscardPlace>5 || secondDiscardPlace==firstDiscardPlace){
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Enter valid integer amount (1-5)> ";
        }
        Card* secondCardToDiscard = playerList.at(0)->getPlayerHand()->getHand().at(secondDiscardPlace-1);

        cout << "Select the third card to discard (1-5)> ";
        int thirdDiscardPlace=0;
        while (!(cin >> thirdDiscardPlace) || thirdDiscardPlace<1 || thirdDiscardPlace>5 || thirdDiscardPlace==secondDiscardPlace || thirdDiscardPlace==firstDiscardPlace){
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Enter valid integer amount (1-5)> ";
        }
        Card* thirdCardToDiscard = playerList.at(0)->getPlayerHand()->getHand().at(thirdDiscardPlace-1);

        deck.obtainCard(playerList.at(0)->getPlayerHand()->distributeCard(firstCardToDiscard->value, firstCardToDiscard->suit));
        deck.obtainCard(playerList.at(0)->getPlayerHand()->distributeCard(secondCardToDiscard->value, secondCardToDiscard->suit));
        deck.obtainCard(playerList.at(0)->getPlayerHand()->distributeCard(thirdCardToDiscard->value, thirdCardToDiscard->suit));

        playerList.at(0)->getPlayerHand()->obtainCard(deck.distributeRandomCard());
        playerList.at(0)->getPlayerHand()->obtainCard(deck.distributeRandomCard());
        playerList.at(0)->getPlayerHand()->obtainCard(deck.distributeRandomCard());
    }
}

void Poker::payout(Player* player){}
