#pragma once
#include <vector>

enum CardSuit {Clubs, Spades, Diamonds, Hearts};
enum CardValue {A, 2, 3, 4, 5, 6, 7, 8, 9, 10, J, Q, K};

struct Card{
	CardSuit suit;
	CardValue value;
}

class Hand{
	protected:
		vector<*Card> hand;
	private:
		void sortHand();
	public:
		void obtainCard(Card*);
		Card* distributeCard(Card*);
		void viewHand();
		void clearHand();	
};
