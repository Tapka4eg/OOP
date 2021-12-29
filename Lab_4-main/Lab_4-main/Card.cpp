#include "Card.h"

Card::Card(Card* card) 
{
	denomination_ = card->getDenomination();
	suit_ = card->getSuit();
}

Card::Card(char denomination, char suit) 
{
	denomination_ = denomination;
	suit_ = suit;
}

Card::~Card() 
{ 
}

char Card::getSuit() 
{ 
	return suit_; 
}

char Card::getDenomination() 
{ 
	return denomination_; 
}

int Card::getPoint()
{
	int score;
	if (denomination_ == 'A') score = 11;
	else if (denomination_ == 'J' || denomination_ == 'Q' || denomination_ == 'K') score = 10;
	else score = atoi(&denomination_);

	return score;
}

ostream& operator<<(ostream& out, Card& card)
{
	out << card.denomination_ << card.suit_;
	return out;
}