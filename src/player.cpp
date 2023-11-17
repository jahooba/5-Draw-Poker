#include "../header/player.hpp"

using namespace std;

Player::Player(string name){
    this->name = name;
    balance = new Balance();
}


Player::Player(string name, int balance){
    this->name = name;
    this->balance = new Balance(balance);
}

Player::~Player(){
    delete balance;
}

string Player::getName(){
    return name;
}

Balance* Player::getBalance(){
    return balance;
}
