#pragma once
#include "../header/hand.hpp"
#include "../header/balance.hpp"
using namespace std;

class Player {
private:
    string name;
    Hand hand;
    Balance balance;
public:
    Player(string name);
    Player(string name, double balance);
    string getName();
    double getBalance();
};
