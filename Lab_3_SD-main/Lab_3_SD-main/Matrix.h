#pragma once
class Matrix
{
private:
	int rows_;
	int cols_;
	double** matrix;

public:
	Matrix(const int rows_, const int cols_);
	~Matrix();

	void operator++();
	void operator++(int);
	void operator--();
	void operator--(int);

	double at(int i, int j);
	void setAt(int i, int j, double val);

	int getRows();
	int getCols();

	void printFormated();

};

