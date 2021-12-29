#pragma once
#include "IFormattable.h"
#include "Deck.h"
#include <string>
#include <iostream>

using namespace std;

class Adapter : public IFormattable 
{
public:
	Adapter();
	string format() override;
	void prettyPrint(const Deck& formatDeck) override;
};
