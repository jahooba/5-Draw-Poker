#pragma once
#include "../header/hand.hpp"
#include "../header/balance.hpp"
using namespace std;

class Player {
protected:
    string name;
    Hand *hand;
    Balance *balance;
    string fileName; 
public:
    Player();
    Player(string name);
    Player(string name, double balance);
    Player(string name, double balance, Hand *hand);
    ~Player();
    string getName();
    Balance* getPlayerBalance();
    Hand* getPlayerHand();
    /*
    void load();
    void save();
    string getFileName();
    void clearFile();
    */
};
