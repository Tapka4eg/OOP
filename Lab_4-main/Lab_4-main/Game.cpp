#include "Game.h"

Game::Game() 
{

	for (int i = 0; i < 4; i++)
	{
		deck[i] = new Deck();
		deck[i]->shuffle();
	}
	player = new Player();
	dealer = new Dealer();
}

Game::~Game() 
{

	for (int i = 0; i < 4; i++) 
	{ 
		delete deck[i];
	}
	delete player;
	delete dealer;
}

void Game::play() 
{
	int size = 0;
	cout << "4 вариант\n --> Тип: европейский\n --> Доп.правила: саррендер\n";
	cout << "Ваш баланс: \n" << player->getBalance() << "$";
	cout << "\nВаша ставка? \n" << endl;
	cin >> bet;

	dealer->addCard(deck[rand() % 4]->pop());
	player->addCard(deck[rand() % 4]->pop());
	player->addCard(deck[rand() % 4]->pop());
	while (match) partGame();
}

void Game::printGame() {

	cout << "Колоды:";
	for (int i = 0; i < 4; i++) 
	{
		cout << "[" << deck[i]->getSize() << "]\t";
	}
	cout << "\nДилер: ";
	for (int i = 0; i < dealer->getHand()->getCards().size(); i++) 
	{
		cout << *dealer->getHand()->getCards().at(i) << "\t";
	}
	cout << "\nВы: ";
	for (int i = 0; i < player->getHand()->getCards().size(); i++) 
	{
		cout << *player->getHand()->getCards().at(i) << "\t";
	}
}

void Game::partGame() 
{
	playerScore = player->getHand()->getScore();
	if (playerScore == 21 && player->getHand()->getCards().size() == 2) 
	{
		blackJack();
	}
	else 
	{
		printGame();
		if (player->getHand()->getCards().size() == 2 && isSurrender == true) 
		{ 
			menuSurrender(); 
		}
		else 
		{
			menu(); 
		}
	}
}

void Game::menu()
{
	cout << "\n1.Хватит\n2.Ещё\n";
	cin >> item;
	dealerScore = dealer->getHand()->getScore();
	playerScore = player->getHand()->getScore();
	if (item == 1) 
	{
		stop(); 
	}
	else if (item == 2) 
	{
		more();
	}
	else 
	{ 
		cout << "Вы ошиблись!\n"; 
	}
}

void Game::menuSurrender()
{
	cout << "\n1.Хватит\n2.Ещё\n3.Снять половину ставки?\n";
	cin >> item;
	dealerScore = dealer->getHand()->getScore();
	playerScore = player->getHand()->getScore();
	if (item == 1) 
	{ 
		stop(); 
	}
	else if (item == 2) 
	{
		more(); 
	}
	else if (item == 3) 
	{
		surrender();
	}
	else
	{ 
		cout << "Вы ошиблись!\n"; 
	}
}

void Game::conditionMaxCard()
{
	if (player->getHand()->getCards().size() == 5 && player->getHand()->getScore() < 21) 
	{
		bet *= 1.5;
		win();
	}
	else if (player->getHand()->getCards().size() == 6 && player->getHand()->getScore() < 21) 
	{
		bet *= 2;
		win();
	}
	else if (player->getHand()->getCards().size() == 7 && player->getHand()->getScore() < 21) 
	{
		bet *= 3;
		win();
	}
}

void Game::more() 
{
	try 
	{
		player->addCard(deck[rand() % 4]->pop());
		playerScore = player->getHand()->getScore();
		conditionMaxCard();
		if (playerScore > 21) 
		{ 
			throw true; 
		}
	}
	catch (...) 
	{
		printGame();

		cout << "\nПеребор! Вы проиграли! Ваш проигрыш: " << bet << ". Ваш баланс: " << player->getBalance() - bet << endl;

		player->clearHand();
		dealer->clearHand();

		match = false;
	}
}

void Game::stop() 
{

	dealer->addCard(deck[rand() % 4]->pop());
	dealerScore = dealer->getHand()->getScore();

	if (dealerScore >= 21) 
	{ 
		win(); 
	}
	if (dealerScore < playerScore) 
	{
		win(); 
	}
	if (dealerScore < 21 && dealerScore >= playerScore) 
	{ 
		losing(); 
	}
}

void Game::surrender() 
{
	bet -= bet / 2;
	cout << "\nВаша ставка сейчас: " << bet << endl;
	isSurrender = false;
}

void Game::losing() 
{
	printGame();

	player->clearHand();
	dealer->clearHand();

	cout << "\nВы проиграли! Ваш проигрыш: " << bet << ". Ваш баланс: " << player->getBalance() - bet << endl;
	match = false;
}

void Game::win() 
{
	printGame();

	player->addMoney(bet);
	player->clearHand();
	dealer->clearHand();

	cout << "\nПоздравляем! Вы выиграли! Ваш выигрыш: " << bet << ". Ваш баланс: " << player->getBalance() << endl;
	match = false;
}

void Game::blackJack() 
{
	printGame();

	player->addMoney(1.5 * bet);
	player->clearHand();
	dealer->clearHand();

	cout << "\nПоздравляем, у вас блэкджэк! Ваш выигрыш: " << bet * 1.5 << ".  Ваш баланс: " << player->getBalance() << endl;
	match = false;
}
