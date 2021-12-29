#include "Deck.h"

Deck::Deck() 
{
	for (int i = 0; i < suits.size(); i++) 
	{
		for (int j = 0; j < denominations.size(); j++) 
		{
			deck.insert(deck.end(), new Card(denominations[j], suits[i]));
		}
	}
}

Deck::~Deck() 
{
	for (std::vector<Card*>::iterator i = deck.begin(); i != deck.end(); i++)
	{
		delete* i;
	}

	deck.clear();
	denominations.clear();
	suits.clear();
}

int Deck::getSize() 
{ 
	return deck.size(); 
}

void Deck::shuffle() 
{
	for (int i = 0; i < 250; i++) 
	{
		std::swap(deck[rand() % deck.size()], deck[rand() % deck.size()]);
	}
}

Card* Deck::at(int i) 
{ 
	return deck[i]; 
}

Card* Deck::pop() 
{
	Card* tmp = new Card(*deck.begin());
	deck.erase(deck.begin());
	return tmp;
}