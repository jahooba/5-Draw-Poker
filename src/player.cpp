#include "../header/hand.hpp"
#include "../header/balance.hpp"
#include "../header/player.hpp"

using namespace std;

//Player::Player(){}

Player::Player(string name){
    this->name = name;
    balance = new Balance();
}


Player::Player(string name, double balance){
    this->name = name;
    this->balance = new Balance(balance);
}

string Player::getName(){
    return name;
}

Balance* Player::getPlayerBalance(){
    return balance;
}
