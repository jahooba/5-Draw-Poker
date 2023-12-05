#pragma once
#include "../header/player.hpp"
#include "../header/hand.hpp"
#include "../header/balance.hpp"
#include "../header/statistics.hpp"
using namespace std;


/*
enum PokerActionType{
    Check = 1,
    Call = 2,
    Bet = 3,
    Fold = 4
};

struct PokerActions{
    double bet;
};

*/


class PokerPlayer: public Player{
private: 
    Statistics pokerStats = Statistics("usernameStatistics.txt", name);

public: 
    PokerPlayer(string name);
    PokerPlayer(string name, double balance);
    void updateStatistics(int, int);
    void viewStatistics();
    //PokerAction pokerMove(int);
};