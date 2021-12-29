#pragma once
#include <vector>
#include <ctime>
#include <iterator>

#include "Card.h"

using namespace std;

class Deck
{
private:

	vector<Card*> deck;
	vector<char> denominations = { 'A','2','3','4','5','6','7','8','9','2','J','Q','K' };
	vector<char> suits = { 3, 4, 5, 6 };

public:

	Deck();
	~Deck();
	int getSize();
	void shuffle();
	Card* at(int);
	Card* pop();
};


