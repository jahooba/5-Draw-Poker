#include "../header/deck.hpp"

using namespace std;

// generates the deck
void Deck::generateDeck(){
    for (int value = Two; value <= A; value++) {

        CardValue value_actual = static_cast<CardValue>(value); 

        for (int suit = Clubs; suit <= Hearts; suit++) {

            CardSuit suit_actual = static_cast<CardSuit>(suit);
            Deck::obtainCard(new Card(value_actual, suit_actual));
        
        }
    }

    Hand::sortHand();
}

Deck::Deck(){
    Deck::generateDeck();
}

Deck::~Deck() {
    Hand::clearHand();
    hand.clear();
}

Card* Deck::distributeRandomCard() {
    srand(0);

    int index = rand() % (hand.size());
    Card* discarded_card = hand.at(index);
    Hand::distributeCard(discarded_card->value, discarded_card->suit);

    return discarded_card;
}

void Deck::obtainCard(Card* card) {
    if (hand.size() < MAX_SIZE) {
        hand.push_back(card);
    }

    Hand::sortHand();

    return;
}

