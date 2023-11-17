#include <unordered_map>
#include "../header/deck.hpp"
//#include "../header/player.hpp"
#include <vector>

//Poker::Poker(vector<Player*> playerList){}

void Poker::generateScoreKey(){
    Hand high_card;         //lowest rank
    Hand one_pair;
    Hand two_pair;
    Hand three_of_a_kind;
    Hand straight;
    Hand flush;
    Hand full_house;
    Hand four_of_a_kind;
    Hand straight_flush;
    Hand royal_flush;       //highest rank

    SCORE_KEY[high_card]       = 1;
    SCORE_KEY[one_pair]        = 2;
    SCORE_KEY[two_pair]        = 3;
    SCORE_KEY[three_of_a_kind] = 4;
    SCORE_KEY[straight]        = 5;
    SCORE_KEY[flush]           = 6;
    SCORE_KEY[full_house]      = 7;
    SCORE_KEY[four_of_a_kind]  = 8;
    SCORE_KEY[straight_flush]  = 9;
    SCORE_KEY[royal_flush]     = 10;
    
}

void Poker::Game_Start(){}

int Poker::getHandScore(Hand hand){}

//void Poker::payout(Player* player){}
