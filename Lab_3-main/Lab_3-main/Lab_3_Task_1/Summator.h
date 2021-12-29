#pragma once
#include "ExpressionEvaluator.h"
#include <fstream>

class Summator : public ExpressionEvaluator
{
public:
	Summator(int n);
	double calculate();

	void logToScreen();
	void logToFile(const std::string& filename);

	~Summator();

};

