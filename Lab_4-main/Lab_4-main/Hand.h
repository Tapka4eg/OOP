#pragma once
#include <vector>
#include <iterator>
#include "Card.h"

using namespace std;

class Hand
{
private:

	vector<Card*> deck;

public:

	Hand();
	~Hand();

	vector<Card*> getCards();
	void addCard(Card*);

	Card* at(int);
	int getScore();
};