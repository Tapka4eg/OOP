#include "Adapter.h"
#include <string>

Adapter::Adapter() { }

string Adapter::format() 
{
	return "������ ���������������. ��� �����...\n";
}

void Adapter::prettyPrint(const Deck& formatDeck)
{
	cout << Adapter::format();
}