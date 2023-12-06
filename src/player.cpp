#include "../header/hand.hpp"
#include "../header/balance.hpp"
#include "../header/player.hpp"

using namespace std;

Player::Player(){}

Player::Player(string name){
    this->name = name;
    balance = new Balance();
}

Player::Player(string name, double balance){
    this->name = name;
    this->balance = new Balance(balance);
}

Player::~Player() {
    if (balance == nullptr) {
        balance = new Balance(0);
    }

    delete balance;
}

string Player::getName() {
    return name;
}

Balance* Player::getBalance(){
    return balance;
}

bool Player::loadPlayer() 
{
    string fileName = "../userdata/" + name + "Player.txt";
    ifstream file(fileName);

    if (file.is_open()) {
        
        string playerName;
        double playerBalance;

        file >> playerName >> playerBalance;

        name = playerName;

        balance->setBalance(playerBalance);

        return true;
    }
     
    file.close();
    return false;
}

bool Player::savePlayer() {
    string fileName = "../userdata/" + name + "Player.txt";
    ofstream file(fileName, ios::app);

    if (file.is_open()) 
    {
        file << getName() << " " << balance->getBalance() << endl;
        return true;
    } 

    file.close();
    return false;
}