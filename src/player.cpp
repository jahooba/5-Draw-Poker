#include "../header/hand.hpp"
#include "../header/balance.hpp"
#include "../header/player.hpp"
#include <iostream>
#include <string>
#include <fstream>
#include <cstring>

using namespace std;

Player::Player() : Player("DEFAULT") {}


Player::Player(string name){
    this->name = name;
    balance = new Balance(name);
    hand = new Hand();
}

Player::Player(string name, double balance){
    this->name = name;
    this->balance = new Balance(name, balance);
    hand = new Hand();
}

Player::Player(string name, double balance, Hand* hand){
    this->name = name;
    this->balance = new Balance(name, balance);
    this->hand = hand;
}

Player::~Player() {
    if (balance == nullptr) {
        balance = new Balance(name, 0);
    }

    if (hand == nullptr) {
        hand = new Hand();
    }

    delete hand;
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


bool Player::loadPlayer() 
{
    string fileName = "userdata/" + name + "Stats.txt";
    ifstream file(fileName);

    if (file.is_open()) {
        return true;
    }
     
    file.close();
    return false;
}

bool Player::savePlayer() {
    string fileName = "userdata/" + name + "Player.txt";
    ofstream file(fileName, ios::app);

    if (file.is_open()) 
    {
        file << getName() << " " << balance->getBalance() << endl;
        return true;
    } 

    file.close();
    return false;
}
