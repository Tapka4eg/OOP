#pragma once
#include "Hand.h"

class Dealer
{
private:

	Hand* hand;

public:

	Dealer();
	~Dealer();
	void addCard(Card*);
	Hand* getHand();
	void clearHand();
};

