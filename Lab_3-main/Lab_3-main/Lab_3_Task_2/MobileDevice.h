#pragma once
#include <string>
#include<iostream>
#include "ICallable.h"

using namespace std;
class MobileDevice : public ICallable
{
public:
	MobileDevice();

	virtual ~MobileDevice();

	virtual void printInfo() = 0;
	
	string getNumber();

protected:
	string type_, color_, manufacturer_, model_, phoneNumber_, lastNumber_;
	double weight_, price_;
	int batery_;
};

