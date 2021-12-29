#include "ExpressionEvaluator.h"
ExpressionEvaluator::ExpressionEvaluator()
{
	size = 20;
	operands = new double[size];
	for (int i = 0; i < size; i++)
	{
		operands[i] = 0;
	}
}
ExpressionEvaluator::ExpressionEvaluator(int n)
{
	size = n;
	operands = new double[size];
	for (int i = 0; i < size; i++)
	{
		operands[i] = 0;
	}
}

void ExpressionEvaluator::setOperand(size_t pos, double value)
{
	operands[pos] = value;
}

void ExpressionEvaluator::setOperands(double* ops, size_t n)
{
	operands = new double[n];
	for (int i = 0; i < n; i++)
	{
		operands[i] = ops[i];
	}
		
}

void ExpressionEvaluator::logToScreen()
{
}

void ExpressionEvaluator::logToFile(const std::string& filename)
{
}

ExpressionEvaluator::~ExpressionEvaluator()
{
	delete[] operands;
}