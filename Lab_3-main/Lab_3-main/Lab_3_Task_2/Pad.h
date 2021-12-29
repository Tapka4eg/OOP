#pragma once
#include <string>
#include "MobileDevice.h"

using namespace std;

class Pad : public MobileDevice
{
public:
	Pad(const string& manufacturer, const string& model, const string& phoneNumber, const string& color, const double& weight, const double& price, const int& batery);

	void call(const std::string& recepient) override;

	void printInfo() override;
	
	~Pad();
};

