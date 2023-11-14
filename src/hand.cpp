#include "../header/hand.hpp"

Hand::obtainCard(Card* card){
	vector.push_back(card);
}

Hand::viewHand(){
	for (auto x:hand) {
    		cout << x << " ";
	}
}

Hand::clearHand(){
	for (auto x:hand) {
    		hand.pop_back(x);
	}
}
