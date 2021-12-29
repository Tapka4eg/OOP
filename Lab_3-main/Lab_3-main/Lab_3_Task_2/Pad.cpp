#include "Pad.h"

Pad::Pad(const string& manufacturer, const string& model, const string& phoneNumber, const string& color, const double& weight, const double& price, const int& batery)
{
	type_ = "Pad";
	manufacturer_ = manufacturer;
	model_ = model;
	phoneNumber_ = phoneNumber;
	color_ = color;
	weight_ = weight;
	price_ = price;
	batery_ = batery;
}

void Pad::call(const std::string& recepient)
{
	cout << "Calling..." << "Successfully. " << "Can Phoenix's communication do that?" << endl;
	lastNumber_ = recepient;
	batery_ -= 10;
}

void Pad::printInfo()
{
	cout << "Info:" << endl;
	cout << "Type - manufacturer, model, color, weight, price:\n"
		<< type_ << " - " << manufacturer_ << ", " << model_ << ", " << color_ << ", " << weight_ << " gr, " << price_ << "$" << endl;
	cout << "Number: " << phoneNumber_ << endl;
	cout << "Last called: " << lastNumber_ << endl;
	cout << "Batery: " << batery_ << "%" << endl << endl;
}

Pad::~Pad()
{
}
