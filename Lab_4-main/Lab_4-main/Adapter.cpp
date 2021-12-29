#include "Adapter.h"
#include <string>

Adapter::Adapter() { }

string Adapter::format() 
{
	return "КОЛОДА отформатирована. Тут пусто...\n";
}

void Adapter::prettyPrint(const Deck& formatDeck)
{
	cout << Adapter::format();
}