#include "Dealer.h"

Dealer::Dealer() 
{ 
	hand = new Hand(); 
}

Dealer::~Dealer() 
{ 
	delete hand; 
}

void Dealer::addCard(Card* card) 
{ 
	hand->addCard(card); 
}

Hand* Dealer::getHand() 
{
	return hand; 
}

void Dealer::clearHand() 
{
	delete hand;
	hand = new Hand();
}
