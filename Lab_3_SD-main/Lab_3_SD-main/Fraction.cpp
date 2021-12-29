#include "Fraction.h"
#include <string>

int Fraction::fractionCounter = 0;

void Fraction::reduce()
{
	int divider = gcd(n_, m_);
	n_ = n_ / divider;
	m_ = m_ / divider;
}

int Fraction::gcd(int m, int n)
{
	int remain;
	if (n < m) {
		while (n % m != 0) {
			remain = n % m;
			n = m;
			m = remain;
		}
	}
	else {
		while (m % n != 0) {
			remain = m % n;
			m = n;
			n = remain;
		}
	}
	return remain;

}

void Fraction::printAsFraction(double decimal_fraction)
{
	std::string inputToString = std::to_string(decimal_fraction);
	const char* inputInChar = inputToString.c_str();
	int m, n;
	int length = strlen(inputInChar);
	int floatDot = 0;
	int lastNonZero = 0;
	int ten = 0;
	for (int i = 0; i < length; i++) {
		if (inputInChar[i] == '.')
			floatDot = i;
		else if (floatDot != 0) {
			++ten;
		}
	}
	n = pow(10, ten);
	m = decimal_fraction * n;
	int delitel = gcd(n, m);
	n /= delitel;
	m /= delitel;
	std::cout << m << '/' << n << std::endl;
}

void Fraction::printAsFraction(char* decimal_fraction)
{
	double inputNum = atof(decimal_fraction);
	int m, n;
	int length = strlen(decimal_fraction);
	int floatDot = 0;
	int lastNonZero = 0;
	int ten = 0;
	for (int i = 0; i < length; i++) {
		if (decimal_fraction[i] == '.')
			floatDot = i;
		else if (floatDot != 0) {
			++ten;
		}
	}
	n = pow(10, ten);
	m = inputNum * n;
	int delitel = gcd(n, m);
	n /= delitel;
	m /= delitel;
	std::cout << m << '/' << n << std::endl;

}

void Fraction::printFraction()
{
	if (n_ < 0)
	{
		std::cout << "-" << n_ * -1 << '/' << m_ << std::endl;
	}
	if (m_ < 0) 
	{
		std::cout << "-" << n_ << '/' << m_ * -1 << std::endl;
	}
	else
	{
		std::cout << n_ << '/' << m_ << std::endl;
	}
}

Fraction::Fraction()
{
	fractionCounter++;

}

Fraction::Fraction(int n, int m)
{
	fractionCounter++;
	n_ = n;
	m_ = m;

}

void Fraction::setM(int m)
{
	m_ = m;
}

void Fraction::setN(int n)
{
	n_ = n;
}

int Fraction::getM()
{
	int m = m_;
	return m;
}

int Fraction::getN()
{
	int n = n_;
	return n;
}

int Fraction::getTotalFractions()
{
	return fractionCounter;
}

Fraction Fraction::operator +(const Fraction& term)
{
	Fraction out;
	int aN = this->n_;
	int aM = this->m_;
	int bN = term.n_;
	int bM = term.m_;
	if (aM == bM)
	{
		out.setN(aN);
		out.setM(aM + bM);
	}
	else 
	{
		int commonMult = aM * bM;
		aM *= bN;
		bM *= aN;
		int totalM = aM + bM;
		int mult = gcd(totalM, commonMult);
		out.setN(totalM / mult);
		out.setM(commonMult / mult);
	}
	return out;
}

Fraction Fraction::operator -(const Fraction& subtrahend)
{
	Fraction out;
	int aN = this->n_;
	int aM = this->m_;
	int bN = subtrahend.n_;
	int bM = subtrahend.m_;
	if (aM == bM) 
	{
		out.setN(aN);
		out.setM(aM + bM);
	}
	else 
	{
		int commonMult = aM * bM;
		aM *= bN;
		bM *= aN;
		int totalM = aN - bN;
		int mult = gcd(totalM, commonMult);
		out.setN(totalM / mult);
		out.setM(commonMult / mult);
	}
	return out;
}

Fraction Fraction::operator *(const Fraction& factor)
{
	Fraction out;
	int aN = this->n_;
	int aM = this->m_;
	int bN = factor.n_;
	int bM = factor.m_;
	int totalN, totalM;
	totalN = aN * bN;
	totalM = aM * bM;
	int mult = gcd(totalM, totalN);
	out.setN(totalN / mult);
	out.setM(totalM / mult);
	return out;
}

Fraction Fraction::operator /(const Fraction& divisor)
{
	Fraction out;
	int aN = this->n_;
	int aM = this->m_;
	int bN = divisor.n_;
	int bM = divisor.m_;
	int totalN, totalM;
	totalN = aN * bM;
	totalM = aM * bN;
	int mult = gcd(totalM, totalN);
	out.setN(totalN / mult);
	out.setM(totalM / mult);
	return out;
}
