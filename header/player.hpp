#pragma once
#include "../header/hand.hpp"
#include "../header/balance.hpp"
using namespace std;

class Player {
protected:
    string name;
    //Hand hand;
    Balance *balance;
public:
    //Player();
    Player(string name);
    Player(string name, double balance);
    string getName();
    Balance* getPlayerBalance();
};
