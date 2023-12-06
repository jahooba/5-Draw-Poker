#include "gtest/gtest.h"
#include "../header/poker.hpp"
#include <iostream>
#include <sstream>
using namespace std;

class PokerMock : public Poker {
public:
    PokerMock() {};
    void setWinner(Player* newWinner) { winner = newWinner; }
    void setPlayerList(vector<PokerPlayer*> playerlist) { playerList = playerlist; }
};

TEST(PokerAction, BetPayout) {
    PokerPlayer* player1 = new PokerPlayer("Jeff", 200);
    PokerPlayer* player2 = new PokerPlayer("Alex", 200);
    vector<PokerPlayer*> players;
    players.push_back(player1);
    players.push_back(player2);

    PokerMock game;
    game.setPlayerList(players);

    player1->pokerMove(Bet, 100);
    player2->pokerMove(Bet, 100);

    game.setWinner(player1);
    game.payout();

    EXPECT_EQ(player1->getPlayerBalance()->getBalance(), 300);
    EXPECT_EQ(player2->getPlayerBalance()->getBalance(), 100);

    delete player1;
    delete player2;
}