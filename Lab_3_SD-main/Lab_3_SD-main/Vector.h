#pragma once

class Vector
{
private:
	int size_;
	double* vector;

public:
	Vector();
	Vector(const int size);
	~Vector();

	int getSize();

	double& operator[] (const int index);
	void operator++(); // post
	void operator++(int); // pre
	void operator--(); // post
	void operator--(int); //pre

	void printFormated();
};

