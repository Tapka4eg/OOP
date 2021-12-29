#pragma once
#include <string>
#include "MobileDevice.h"

using namespace std;

class Phone : public MobileDevice
{
public:
	Phone(const string& manufacturer, const string& model, const string& phoneNumber, const string& color, const double& bill, const double& weight, const double& price, const int& batery);

	void call(const std::string& recepient) override;

	void printInfo() override;

	~Phone();

private:
	double bill_;
};

