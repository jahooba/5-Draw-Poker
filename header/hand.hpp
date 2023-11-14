#pragma once
#include <vector>

enum CardSuit {Clubs, Spades, Diamonds, Hearts};
enum CardValue {A, Two, Three, Four, Five, Six, Seven, Eight, Nine, Ten, J, Q, K};

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
