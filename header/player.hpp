#pragma once

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