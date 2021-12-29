#include "CustomExpressionEvaluator.h"
#include <iostream>

using namespace std;

CustomExpressionEvaluator::CustomExpressionEvaluator(int n) : ExpressionEvaluator(n) {}

double CustomExpressionEvaluator::calculate()
{
	double res = 0;
	for (int i = 0; i < size; i++)
	{
		res += (i + 1) * operands[i];
	}
	return res;
}

void CustomExpressionEvaluator::logToScreen()
{
	cout << "<CustomExpressionEvaluator>" << endl;
	cout << size << " operands :" << endl;
	if (operands[0] >= 0)
	{
		cout << operands[0];
	}
	else
	{
		cout << '(' << operands[0] << ')';
	}
	

	for (int i = 1; i < size; ++i)
	{
		if (operands[0] >= 0)
		{
			cout << " + " << i + 1 << " * " << operands[i];
		}
		else
		{
			cout << " + " << i + 1 << " * (" << operands[i] << ") ";
		}
	}

	cout << "\n -> " << calculate() << endl << endl;
}

void CustomExpressionEvaluator::logToFile(const std::string& filename)
{
	ofstream stream;
	stream.open(filename, ios_base::app);

	stream << "<CustomExpressionEvaluator>" << endl;
	stream << size << " operands :" << endl;
	operands[0] >= 0 ? stream << operands[0] : stream << '(' << operands[0] << ')';

	for (int i = 1; i < size; i++)
	{
		if (operands[0] >= 0)
		{
			stream << " + " << i + 1 << " * " << operands[i];
		}
		else
		{
			stream << " + " << i + 1 << " * (" << operands[i] << ")";
		}
	}

	stream << "\n -> " << calculate() << endl << endl;

	stream.close();
}

void CustomExpressionEvaluator::shuffle()
{
	double tmp;
	for (int i = 0; i < size - 1; i++)
	{
		int max = i;
		for (int j = i + 1; j < size; j++)
		{
			if (operands[j] > operands[max])
			{
				max = j;
			}
		}
		tmp = operands[max];
		operands[max] = operands[i];
		operands[i] = tmp;
	}
}

void CustomExpressionEvaluator::shuffle(size_t left, size_t right)
{
	double tmp;
	for (int i = left; i < right - 1; i++)
	{
		int max = i;
		for (int j = i + 1; j < right; j++)
		{
			if (operands[j] > operands[max])
			{
				max = j;
			}
		}
		tmp = operands[max];
		operands[max] = operands[i];
		operands[i] = tmp;
	}
}

CustomExpressionEvaluator::~CustomExpressionEvaluator()
{
}