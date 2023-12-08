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
	PokerAction(PokerActionType t, double b) : type(t), bet(b) {}
};


class PokerPlayer: public Player{

protected: 
    Statistics pokerStats;
    PokerAction* currAction = nullptr;
    double currMaxBet = 0;
    double absoluteMaxBet = 0;
    
public:
    PokerPlayer();
    PokerPlayer(string name);
    PokerPlayer(string name, double balance);
    PokerPlayer(string name, double balance, Hand* hand);
    ~PokerPlayer();
    void updateStatistics(int, int);
    void viewStatistics();
    void viewBalance();
    virtual PokerAction* pokerMove();
    PokerAction* pokerMove(PokerActionType, double betAmountAdded);
    PokerAction* getRecentMove() { return currAction; }
    void clearAction();
    void setCurrMaxBet(double newCurrMaxBet) { currMaxBet = newCurrMaxBet; }
    void setAbsMaxBet(double newAbsMaxBet) { absoluteMaxBet = newAbsMaxBet; }
    double getAbsMaxBet() { return absoluteMaxBet; }
};