#pragma once
#include "ILoggable.h"
#include "IShuffle.h" 

class ExpressionEvaluator : public ILoggable
{
public:
	double* operands;
	int size;

	ExpressionEvaluator();
	ExpressionEvaluator(int size);

	void setOperand(size_t pos, double value);
	void setOperands(double* ops, size_t n);

	void logToScreen();
	void logToFile(const std::string& filename);

	virtual double calculate() = 0;

	virtual ~ExpressionEvaluator();

};

