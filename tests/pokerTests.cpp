#include "gtest/gtest.h"
#include "../header/poker.hpp"

using namespace std;

TEST(PokerGameTests, GameTest) {
    vector<PokerPlayer*> playerList;
    Hand* handOne = new Hand();
    playerList.push_back(new PokerPlayer("PlayerOne", 1.5 , handOne));
    Hand* handTwo = new Hand();
    playerList.push_back(new PokerPlayer("PlayerTwo", 200, handTwo));

    Poker game(playerList);
    EXPECT_NO_THROW(game.Game_Start());

    for (PokerPlayer* player : playerList) {
        delete player;
    }
}

TEST(PokerGameTests, GameWithNoCreditsTest){
    vector<PokerPlayer*> playerList;
    Hand* handOne = new Hand();
    playerList.push_back(new PokerPlayer("PlayerOne", 0, handOne));
    Hand* handTwo = new Hand();
    playerList.push_back(new PokerPlayer("PlayerTwo", 200, handTwo));

    Poker game(playerList);
    EXPECT_NO_THROW(game.Game_Start());

    for (PokerPlayer* player : playerList) {
        delete player;
    }
}

TEST(PokerDiscardRoundTests, DiscardTest){
    vector<PokerPlayer*> playerList;
    playerList.push_back(new PokerPlayer());
    playerList.push_back(new PokerPlayer());
    Poker game(playerList);
    EXPECT_NO_THROW(game.discardRound());

    for (PokerPlayer* player : playerList) {
        delete player;
    }
}

