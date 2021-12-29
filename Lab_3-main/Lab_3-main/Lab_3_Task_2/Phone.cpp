#include "Phone.h"

Phone::Phone(const string& manufacturer, const string& model, const string& phoneNumber, const string& color, const double& bill, const double& weight, const double& price, const int& batery)
{
	type_ = "Phone";
	manufacturer_ = manufacturer;
	model_ = model;
	phoneNumber_ = phoneNumber;
	color_ = color;
	bill_ = bill;
	weight_ = weight;
	price_ = price;
	batery_ = batery;
}

void Phone::call(const std::string& recepient)
{
	cout << "Calling..." << endl;
	 
	int equal = 1;

	if (recepient.length() >= 7 && recepient.length() <= 15 && recepient[0] == '+') 
	{
		for (int i = 1; i < recepient.length(); i++)
		{
			if ( recepient[i] >= '0' && recepient[i] <= '9')
			{
				equal++;
			}
			else
			{
				cout << "Invalid number" << endl;
				break;
			}
		}
	}
	else
	{
		cout << "Invalid number" << endl;
	}
	if (equal >= recepient.length())
	{
		lastNumber_ = recepient;
		bill_ -= 0.1;
		batery_ -= 3;
		cout << "Successfully" << endl;
	}
	
}

void Phone::printInfo()
{
	cout << "Info:" << endl;
	cout << "Type - manufacturer, model, color, weight, price:\n" 
		 << type_ << " - " << manufacturer_ << ", " << model_ << ", " << color_ << ", " << weight_ << " gr, " << price_ << "$ " << endl;
	cout << "Number: " << phoneNumber_ << endl;
	cout << "Last called: " << lastNumber_ << endl;
	cout << "Bill: " << bill_ << "$" << endl;
	cout << "Batery: " << batery_ << "%" << endl << endl;
}

Phone::~Phone()
{
}
