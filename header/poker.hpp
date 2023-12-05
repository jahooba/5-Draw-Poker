#pragma once

#include "../header/hand.hpp"
#include "../header/deck.hpp"
#include "../header/player.hpp"
#include "../header/pokerScoreKey.hpp"

#include <vector>
#include <limits>

using namespace std;

class Poker{
	private:
		Deck deck;
		PokerScoreKey POKER_SCORE_KEY;
		vector<Player*> playerList;
		double pot;
	public:
		Poker(vector<Player*> playerList);
		~Poker();
		void Game_Start();
		void discardRound();
		void payout(Player*);
};