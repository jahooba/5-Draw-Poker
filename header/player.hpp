#pragma once
#include "../header/hand.hpp"
#include "../header/balance.hpp"
#include <fstream>
using namespace std;

class Player {
    protected:
        string name;
        Hand hand;
        Balance *balance;
    public:
        Player();
        Player(string name);
        Player(string name, double balance);
        ~Player();
        string getName();
        Balance* getBalance();
        bool loadPlayer();
        bool savePlayer();
};
