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
    //While the player has enough money and wants to play or only one player left
    while (playerList.at(0)->getBalance() > 0 && playAgain == true && playerList.size() > 1){
        //Distribute cards from deck to each player
        playerList.at(0)->getHand()->obtainCard(deck.distributeRandomCard());
        playerList.at(0)->getHand()->obtainCard(deck.distributeRandomCard());
        playerList.at(0)->getHand()->obtainCard(deck.distributeRandomCard());
        playerList.at(0)->getHand()->obtainCard(deck.distributeRandomCard());
        playerList.at(0)->getHand()->obtainCard(deck.distributeRandomCard());

        //Present Poker actions for each player

        //Discard and draw for each player
        discardRound();
        //Present Poker actions for each player

        //Reveal hands for each player and decide winner
        
        //Prompt user with menu
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

void Poker::discardRound(){
    cout << "\n\tDISCARD ROUND\nHow many cards will you discard?\n(0-3) >";
    int discardAmount=-1;
    while (!(cin >> discardAmount) || discardAmount<0 || discardAmount>3){
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Enter valid integer amount (0-3)> ";
    }

    int firstDiscardPlace=0, secondDiscardPlace=0, thirdDiscardPlace=0;
    switch (discardAmount)
    {
    case 1:
        cout << "| 1st card = 1 | 2nd card = 2 | 3rd card= 3 | 4th card = 4 | 5th card = 5 |\n";
        cout << "Select the card to discard (1-5)> ";
        while (!(cin >> firstDiscardPlace) || firstDiscardPlace<1 || firstDiscardPlace>5){
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Enter valid integer amount (1-5)> ";
        }
        break;

    case 2:
        cout << "| 1st card = 1 | 2nd card = 2 | 3rd card= 3 | 4th card = 4 | 5th card = 5 |\n";
        cout << "Select the first card to discard (1-5)> ";
        while (!(cin >> firstDiscardPlace) || firstDiscardPlace<1 || firstDiscardPlace>5){
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Enter valid integer amount (1-5)> ";
        }

        cout << "Select the second card to discard (1-5)> ";
        while (!(cin >> secondDiscardPlace) || secondDiscardPlace<1 || secondDiscardPlace>5 || secondDiscardPlace==firstDiscardPlace){
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Enter valid integer amount (1-5)> ";
        }
        break;

    case 3:
        cout << "| 1st card = 1 | 2nd card = 2 | 3rd card= 3 | 4th card = 4 | 5th card = 5 |\n";
        cout << "Select the first card to discard (1-5)> ";
        while (!(cin >> firstDiscardPlace) || firstDiscardPlace<1 || firstDiscardPlace>5){
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Enter valid integer amount (1-5)> ";
        }

        cout << "Select the second card to discard (1-5)> ";
        while (!(cin >> secondDiscardPlace) || secondDiscardPlace<1 || secondDiscardPlace>5 || secondDiscardPlace==firstDiscardPlace){
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Enter valid integer amount (1-5)> ";
        }

        cout << "Select the third card to discard (1-5)> ";
        while (!(cin >> thirdDiscardPlace) || thirdDiscardPlace<1 || thirdDiscardPlace>5 || thirdDiscardPlace==secondDiscardPlace || thirdDiscardPlace==firstDiscardPlace){
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Enter valid integer amount (1-5)> ";
        }
        break;
    
    default:
        break;
    }
    
}

void Poker::payout(Player* player){}
