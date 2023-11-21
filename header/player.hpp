#pragma once

#include <iostream>
#include "../header/hand.hpp"
#include "../header/balance.hpp"

class Player {
	protected:
		string name;
		Hand hand;
		Balance balance;
	public:
		Player(string);
		Player(string, int);
		string getName();
};
