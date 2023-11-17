#pragma once
#include "../header/player.hpp"
#include "../header/statistics.hpp"
using namespace std;

class PokerPlayer: public Player(){
private: 
    Statistics pokerStats;

public: 
    void updateStatistics(int, int);
    void viewStatistics();
    //PokerAction pokerMove(int);
};