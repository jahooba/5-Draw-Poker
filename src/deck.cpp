#include "../header/deck.hpp"
#include "../header/hand.hpp"

using namespace std;

// generates the deck
void Deck::generateDeck(){
    for (int value = Two; value <= A; value++) {

        CardValue value_actual = static_cast<CardValue>(value); 

        for (int suit = Clubs; suit <= Hearts; suit++) {

            CardSuit suit_actual = static_cast<CardSuit>(suit);
            
            Card* newCard = new Card(value_actual, suit_actual);
            Deck::obtainCard(newCard);
        
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

Card* Deck::distributeRandomCard(){
    return nullptr;
}

void Deck::obtainCard(Card* card) {
    if (hand.size() < MAX_SIZE) {
        hand.push_back(card);
    }

    Hand::sortHand();

    return;
}

