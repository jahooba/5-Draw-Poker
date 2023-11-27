#include "../header/hand.hpp"
#include "../header/balance.hpp"
#include "../header/player.hpp"

using namespace std;

Player::Player(){}

Player::Player(string name){
    this->name = name;
    balance = new Balance();
}

Player::Player(string name, Hand& hand){
    this->name = name;
    this->hand = hand;
    balance = new Balance();
}

Player::Player(string name, double balance){
    this->name = name;
    this->balance = new Balance(balance);
}

string Player::getName(){
    return name;
}

Hand& Player::getPlayerHand(){
    return hand;
}

Balance* Player::getBalance(){
    return balance;
}
