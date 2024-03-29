#pragma once
#include "../header/hand.hpp"
#include "../header/balance.hpp"
#include <fstream>
using namespace std;

class Player {
protected:
    string name;
    Hand* hand;
    Balance* balance;
public:
    Player();
    Player(string name);
    Player(string name, double balance);
    Player(string name, double balance, Hand *hand);
    ~Player();
    string getName();
    Balance* getPlayerBalance();
    Hand* getPlayerHand();
    bool loadPlayer();
    bool savePlayer();
};
