#pragma once
#include<iostream>
#include <string>
#include <fstream>

class Phone
{
private:
	std::string model_;
	std::string number_;
	std::string lastNumber_;
	double bill_;
public:
	Phone();
	Phone(const std::string& model, const std::string& number, const std::string& lastNuber,  const double& bill);

	std::string getModel();
	void setModel(const std::string& model);

	std::string getNumber();
	void setNumber(const std::string& number);

	std::string getLastNuber();
	void setLastNuber(const std::string lastNumber);

	double getBill();
	void setBill(const double bill);

	void call(const std::string& lastNuber, double seconds);

	void serialize();
	void deserialize();

	void serialize(const std::string& filename);
	void deserialize(const std::string& filename);

	void getInfo();
};

