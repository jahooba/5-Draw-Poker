#pragma once
#include <unordered_map>
#include "../header/deck.hpp"
#include "../header/player.hpp"
#include <vector>

class Poker{
	private:
		Deck deck;
		unordered_map<string, int> SCORE_KEY;
		vector<Player*> playerList;
		double pot;
		void generateScoreKey();
	public:
		Poker(vector<Player*> playerList);
		void Game_Start();
		int getHandScore(Hand);
		void payout(Player*);
};

