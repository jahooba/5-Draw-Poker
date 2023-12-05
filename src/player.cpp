#include "../header/hand.hpp"
#include "../header/balance.hpp"
#include "../header/player.hpp"
#include <iostream>
#include <string>
#include <fstream>
#include <cstring>

using namespace std;

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

/*
void Player::save(){
    fstream file;
    file.open(fileName);
    Player::clearFile();

    if (file.is_open()) {
        file << name << " " << balance->getBalance() << endl;
    }

    file.close();
}

void Player::load(){
    fstream file(fileName);
    if(file){
        string playerName;
        while(file >> name){
            if(playerName == name){
                double temp;
                file >> temp;
                balance->setBalance(temp);
            }
        }
    }
}

string Player::getFileName(){
    fileName = "userdata/" + name + "Stats.txt";
}

void Player::clearFile() {
    std::ofstream ofs;
    ofs.open(fileName, std::ofstream::out | std::ofstream::trunc);
    ofs.close();
}

*/
