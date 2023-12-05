#pragma once

#include "../header/hand.hpp"
#include "../header/deck.hpp"
#include "../header/player.hpp"
#include "../header/pokerScoreKey.hpp"

#include <vector>

using namespace std;

class Poker {
	private:
		Deck deck;
		PokerScoreKey POKER_SCORE_KEY;
		vector<PokerPlayer*> playerList;
		double pot;
		Player* winner;
	public:
		Poker(vector<PokerPlayer*> playerList);
		~Poker();
		void Game_Start();
		const int getHandScore(const Hand& ) const;
		void payout();
};