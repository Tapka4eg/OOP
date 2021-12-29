#pragma once
#include <string>
#include "Dealer.h"
#include "Deck.h"
#include "Player.h"

using namespace std;

class Game
{
private:

	Deck* deck[4];
	Player* player;
	Dealer* dealer;
	int dealerScore;
	int playerScore;
	bool match = true;
	bool isSurrender = true;
	int item;
	int bet;

public:
	Game();
	~Game();

	void play();
	void printGame();
	void partGame();
	void menu();
	void menuSurrender();

	void conditionMaxCard();
	void more();
	void stop();

	void surrender();
	void losing();
	void win();
	void blackJack();
};