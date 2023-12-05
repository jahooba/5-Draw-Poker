#include "../header/hand.hpp"
#include "../header/balance.hpp"
#include "../header/player.hpp"

using namespace std;

//Player::Player(){}

Player::Player(string name){
    this->name = name;
    balance = new Balance();
    hand = new Hand();
}

Player::Player(string name, double balance){
    this->name = name;
    this->balance = new Balance(balance);
    hand = new Hand();
}

Player::Player(string name, double balance, Hand* hand){
    this->name = name;
    this->balance = new Balance(balance);
    this->hand = hand;
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

Balance* Player::getPlayerBalance(){
    return balance;
}

Hand* Player::getPlayerHand(){
    return hand;
}
