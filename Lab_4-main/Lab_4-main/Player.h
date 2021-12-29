#pragma once
#include "Hand.h"

class Player
{
private:

	Hand* hand;
	int balance_ = 50000;
	int bet_ = 0;

public:

	Player();
	~Player();
	void addCard(Card*);
	void addMoney(int);
	Hand* getHand();
	int getBalance();

	void clearHand();
};
