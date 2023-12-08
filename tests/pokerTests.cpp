#include "gtest/gtest.h"
#include "../header/poker.hpp"

using namespace std;

TEST(PokerGameTests, GameTest) {
    vector<PokerPlayer*> playerList;
  
    Hand* handOne = new Hand();
    playerList.push_back(new PokerPlayer("PlayerOne", 100 , handOne));
  
    Hand* handTwo = new Hand();
    playerList.push_back(new PokerPlayer("PlayerTwo", 200, handTwo));

    Poker game(playerList);
    EXPECT_NO_THROW(game.Game_Start());

    for (PokerPlayer* player : playerList) {
        delete player;
    }
}

TEST(PokerGameTests, PlayerWithNoCreditsTest){
    vector<PokerPlayer*> playerList;
    Hand* handOne = new Hand();
    playerList.push_back(new PokerPlayer("PlayerOne", 5, handOne));
    Hand* handTwo = new Hand();
    playerList.push_back(new PokerPlayer("PlayerTwo", 200, handTwo));

    Poker game(playerList);
    EXPECT_NO_THROW(game.Game_Start());

    for (PokerPlayer* player : playerList) {
        delete player;
    }
}

