#pragma once
#include "ExpressionEvaluator.h"
#include <fstream>

class Multiplier : public ExpressionEvaluator
{
public:
	Multiplier(int n);
	double calculate();

	void logToScreen();
	void logToFile(const std::string& filename);

	~Multiplier();
};

