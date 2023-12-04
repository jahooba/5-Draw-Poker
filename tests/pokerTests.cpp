#include "gtest/gtest.h"
#include "../header/poker.hpp"

using namespace std;

TEST(PokerDiscardRoundTests, DiscardTest){
    vector<Player*> playerList;
    playerList.push_back(new Player());
    playerList.push_back(new Player());
    Poker game(playerList);
    EXPECT_NO_THROW(game.discardRound());
}

/*TEST(PokerGameTests, GameTest){
    vector<Player*> playerList;
    playerList.push_back(new Player());
    playerList.push_back(new Player());
    playerList.at(0)->getBalance()->setBalance(1);
    Poker game(playerList);
    EXPECT_NO_THROW(game.Game_Start());
}*/


int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
