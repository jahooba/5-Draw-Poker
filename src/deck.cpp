#include "../header/deck.hpp"

using namespace std;

// generates the deck
void Deck::generateDeck(){
    for (int value = Two; value <= A; value++) {

        CardValue valueActual = static_cast<CardValue>(value); 

        for (int suit = Clubs; suit <= Hearts; suit++) {

            CardSuit suitActual = static_cast<CardSuit>(suit);
            Deck::obtainCard(new Card(valueActual, suitActual));
        
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
    srand(time(0));

    int index = rand() % (hand.size());
    Card* discardedCard = hand.at(index);
    Hand::distributeCard(discardedCard->value, discardedCard->suit);

    return discardedCard;
}

void Deck::obtainCard(Card* card) {
    if (hand.size() < MAX_SIZE) {
        hand.push_back(card);
    }

    Hand::sortHand();

    return;
}

void Deck::reset() {
    Hand::clearHand();
    Deck::generateDeck();
}

