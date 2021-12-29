#pragma once
#include "ExpressionEvaluator.h"
#include "IShuffle.h"
#include <fstream>

class CustomExpressionEvaluator : public ExpressionEvaluator, public IShuffle
{

public:

	CustomExpressionEvaluator(int n);
	double calculate();

	void logToScreen();
	void logToFile(const std::string& filename);

	void shuffle();
	void shuffle(size_t i, size_t j);

	~CustomExpressionEvaluator();
};


