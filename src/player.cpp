#include "../header/player.hpp"

using namespace std;

Player::Player(string name){
    this->name = name;
    balance = Balance();
}


Player::Player(string name, double balance){
    this->name = name;
    this->balance = Balance(balance);
}

string Player::getName(){
    return name;
}

double Player::getBalance(){
    return balance.getBalance();
}
