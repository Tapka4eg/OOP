#include "Hand.h"

Hand::Hand() 
{
}

Hand::~Hand() 
{
	for (vector<Card*>::iterator i = deck.begin(); i < deck.end(); i++) 
	{ 
		delete* i; 
	}
}

vector<Card*> Hand::getCards() 
{
	return deck; 
}

void Hand::addCard(Card* card) 
{
	deck.insert(deck.end(), card);
}

Card* Hand::at(int i) 
{ 
	return deck[i]; 
}

int Hand::getScore() 
{
	int score = 0;

	for (int i = 0; i < deck.size(); i++) 
	{
		if (score > 21 && this->at(i)->getPoint() == 11) 
		{ 
			score++; 
		}
		else 
		{ 
			score += this->at(i)->getPoint(); 
		}
	}

	return score;
}