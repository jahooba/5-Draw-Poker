#pragma once
#include "../header/hand.hpp"
#include "../header/deck.hpp"
#include "../header/player.hpp"
#include "../header/pokerScoreKey.hpp"

#include <unordered_map>
#include <vector>


class Poker{
	private:
		Deck deck;
		unordered_map<string, int> POKER_SCORE_KEY;
		vector<Player*> playerList;
		double pot;
		void generateScoreKey();
	public:
		Poker(vector<Player*> playerList);
		~Poker();
		void Game_Start();
		const int getHandScore(const Hand& ) const;
		void payout(Player*);
};

