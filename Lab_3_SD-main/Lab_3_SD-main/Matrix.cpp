#include "Matrix.h"
#include <iostream>
#include <iomanip> 

Matrix::Matrix(const int rows, const int cols)
{
	rows_ = rows;
	cols_ = cols;
	matrix = new double* [rows_];
	for (int i = 0; i < rows_; i++)
	{
		matrix[i] = new double[cols_];
	}
}

Matrix::~Matrix()
{
	for (int i = 0; i < rows_; i++)
	{
		delete[] matrix[i];
	}
	delete[] matrix;
}


void Matrix::operator++()
{
	for (int i = 0; i < rows_; i++) {
		for (int j = 0; j < cols_; j++) {
			matrix[i][j]++;
		}
	}
}

void Matrix::operator++(int)
{
	for (int i = 0; i < rows_; i++) {
		for (int j = 0; j < cols_; j++) {
			++matrix[i][j];
		}
	}
}

void Matrix::operator--()
{
	for (int i = 0; i < rows_; i++) {
		for (int j = 0; j < cols_; j++) {
			matrix[i][j]--;
		}
	}
}

void Matrix::operator--(int)
{
	for (int i = 0; i < rows_; i++) {
		for (int j = 0; j < cols_; j++) {
			--matrix[i][j];
		}
	}
}

double Matrix::at(int i, int j)
{

	return matrix[i][j];
}

void Matrix::setAt(int i, int j, double val)
{
	matrix[i][j] = val;
}

int Matrix::getRows()
{
	int rows = rows_;
	return rows;
}

int Matrix::getCols()
{
	int cols = cols_;
	return cols;
}

void Matrix::printFormated()
{
	for (int i = 0; i < rows_; i++) 
	{
		for (int j = 0; j < cols_; j++) 
		{
			std::cout << std::setw(14) << matrix[i][j];
		}
		std::cout << "\n";
	}
	std::cout << "\n";
}