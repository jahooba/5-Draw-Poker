#pragma once
#include "../header/player.hpp"
#include "../header/hand.hpp"
#include "../header/balance.hpp"
#include "../header/statistics.hpp"
#include "../header/poker.hpp"

using namespace std;

enum PokerActionType {
	Check,
	Call,
	Bet,
	Fold
};

struct PokerAction {
	PokerActionType type;
	double bet;
	PokerAction(PokerActionType t, double b) : type(t), bet(b) {}
};


class PokerPlayer: public Player{
private: 
    Statistics pokerStats;
    PokerAction* currAction = nullptr;
    
public: 
    PokerPlayer(string name);
    PokerPlayer(string name, double balance);
    ~PokerPlayer();
    void updateStatistics(int, int);
    void viewStatistics();
    PokerAction* pokerMove();
    PokerAction* pokerMove(PokerActionType, double);
    PokerAction* getRecentMove() { return currAction; }
};