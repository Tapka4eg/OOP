#pragma once
#include <iostream>

using namespace std;

class Card
{
private:

	char denomination_;
	char suit_;

public:
	Card(Card*);
	Card(char, char);
	~Card();
	char getSuit();
	char getDenomination();
	int getPoint();
	friend ostream& operator<<(ostream&, Card&);
};
