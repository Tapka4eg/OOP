#include "Player.h"

Player::Player()
{ hand = new Hand(); }

Player::~Player()
{
	delete hand; 
}

void Player::addCard(Card* card) 
{
	hand->addCard(card); 
}

void Player::addMoney(int money)
{
	balance_ += money;
}

Hand* Player::getHand() 
{ 
	return hand;
}

int Player::getBalance() 
{
	return balance_;
}

void Player::clearHand() 
{
	delete hand;
	hand = new Hand();
}