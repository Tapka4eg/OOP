#include "Multiplier.h"
#include <iostream>

using namespace std;

Multiplier::Multiplier(int n) : ExpressionEvaluator(n) { }

double Multiplier::calculate()
{
	double mult = operands[0];
	for (int i = 1; i < size; i++)
	{
		mult *= operands[i];
	}
	return mult;
}

void Multiplier::logToScreen()
{
	cout << "<Multiplier>" << endl;
	cout << size << " operands :" << endl;
	if (operands[0] >= 0)
	{
		cout << operands[0];
	}
	else
	{
		cout << '(' << operands[0] << ')';
	}

	for (int i = 1; i < size; i++)
	{
		if (operands[i] >= 0)
		{
			cout << " * " << operands[i];
		}
		else
		{
			cout << " * (" << operands[i] << ") ";
		}
	}
	cout << "\n -> " << calculate() << endl << endl;
}

void Multiplier::logToFile(const std::string& filename)
{
	ofstream stream;
	stream.open(filename, ios_base::app);

	stream << "<Multiplier>" << endl;
	stream << size << " operands :" << endl;
	if (operands[0] >= 0)
	{
		stream << operands[0];
	}
	else
	{
		stream << '(' << operands[0] << ')';
	}

	for (int i = 1; i < size; i++)
	{
		if (operands[i] >= 0)
		{
			stream << " * " << operands[i];
		}
		else
		{
			stream << " * (" << operands[i] << ")";
		}
	}

	stream << "\n -> " << calculate() << endl << endl;
	stream.close();
}


Multiplier::~Multiplier()
{
}