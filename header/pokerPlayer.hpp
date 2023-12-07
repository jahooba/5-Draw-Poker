#pragma once
#include "../header/player.hpp"
#include "../header/hand.hpp"
#include "../header/balance.hpp"
#include "../header/statistics.hpp"

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
	PokerAction(PokerctionType t, double b) : type(t), bet(b) {}
};


class PokerPlayer: public Player{

protected: 
    Statistics pokerStats;
    PokerAction* currAction = nullptr;
    double currMaxBet;
    double absoluteMaxBet;
    
public:
    PokerPlayer();
    PokerPlayer(string name);
    PokerPlayer(string name, double balance);
    PokerPlayer(string name, double balance, Hand* hand);
    ~PokerPlayer();
    void updateStatistics(int, int);
    void viewStatistics();
    virtual PokerAction* pokerMove();
    PokerAction* pokerMove(PokerActionType, double betAmountAdded);
    PokerAction* getRecentMove() { return currAction; }
    void setCurrMaxBet(double newCurrMaxBet) { currMaxBet = newCurrMaxBet; }
    void setAbsMaxBet(double newAbsMaxBet) { absoluteMaxBet = newAbsMaxBet; }
};