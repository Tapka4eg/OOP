#include "Vector.h"
#include <iostream>
#include <iomanip> 

Vector::Vector()
{
	vector = new double[1];
	size_ = 1;
}

Vector::Vector(const int size) {
	vector = new double[size];
	size_ = size;
}

Vector::~Vector()
{
	delete[] vector;
}

int Vector::getSize()
{
	int size = size_;
	return size;
}

double& Vector::operator[](const int index)
{
	return vector[index];
}

void Vector::operator++()
{
	for (int i = 0; i < size_; i++) {
		vector[i]++;
	}

}

void Vector::operator++(int)
{
	for (int i = 0; i < size_; i++)
	{
		++vector[i];
	}

}

void Vector::operator--()
{
	for (int i = 0; i < size_; i++) {
		vector[i]--;
	}

}

void Vector::operator--(int)
{
	for (int i = 0; i < size_; i++)
	{
		--vector[i];
	}

}

void Vector::printFormated()
{
	for (int i = 0; i < size_; i++) 
	{
		std::cout << vector[i] << " " << std::setw(14);
	}
	std::cout << "\n" << "\n";
}	