#pragma once

#include "../header/hand.hpp"
#include "../header/deck.hpp"
#include "../header/pokerPlayer.hpp"
#include "../header/pokerScoreKey.hpp"
#include <limits>
#include <vector>

using namespace std;

class Poker {
	protected:
		Deck deck;
		PokerScoreKey POKER_SCORE_KEY;
		vector<PokerPlayer*> playerList;
		double pot=0;
		PokerPlayer* winner;
	public:
		Poker();
		Poker(vector<PokerPlayer*> playerList);
		~Poker();
		void Game_Start();
		const int getHandScore(const Hand&);
		void payout();
		Player* getWinner() { return winner; }
		void playerActionRound(int);
		void computerActionRound(PokerPlayer*);
		void playerDiscardRound(PokerPlayer*);
		void computerDiscardRound(PokerPlayer*);
		void revealHands();
};