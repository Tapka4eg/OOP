#include "Summator.h"
#include <iostream>

using namespace std;

Summator::Summator(int n) : ExpressionEvaluator(n) { }

double Summator::calculate()
{
	double sum = 0;
	for (int i = 0; i < size; i++)
	{
		sum += operands[i];
	}	
	return sum;
}

void Summator::logToScreen()
{
	cout << "<Summator>" << endl;
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
			cout << " + " << operands[i];
		}
		else
		{
			cout << " + (" << operands[i] << ") ";
		}
	}
	
	cout << "\n -> " << calculate() << endl << endl;
}

void Summator::logToFile(const std::string& filename)
{
	ofstream stream;
	stream.open(filename, ios_base::app);

	stream << "<Summator>" << endl;
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
			stream << " + " << operands[i];
		}
		else
		{
			stream << " + (" << operands[i] << ")";
		}
	}

	stream << "\n -> " << calculate() << endl << endl;
	stream.close();
}


Summator::~Summator()
{
}