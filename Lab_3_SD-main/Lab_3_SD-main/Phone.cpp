#include "Phone.h"

Phone::Phone()
{
}

Phone::Phone(const std::string& model, const std::string& number, const std::string& lastNuber, const double& bill)
{
	model_ = model;
	number_ = number;
	lastNumber_ = lastNuber;
	bill_ = bill;
}

std::string Phone::getModel()
{
	std::string model = model_;
	return model;
}

void Phone::setModel(const std::string& model)
{
	model_ = model;
}

std::string Phone::getNumber()
{
	std::string number = number_;
	return number;
}

void Phone::setNumber(const std::string& number)
{
	number_ = number;
}

std::string Phone::getLastNuber()
{
	std::string lastNumber = lastNumber_;
	return lastNumber;
}

void Phone::setLastNuber(const std::string lastNumber)
{
	lastNumber_ = lastNumber;
}

double Phone::getBill()
{
	double bill = bill_;
	return bill;
}

void Phone::setBill(const double bill)
{
	bill_ = bill;
}

void Phone::call(const std::string& calledNuber, double seconds)
{
	if (getBill() > 0)
	{
		setLastNuber(calledNuber);
		double total = getBill() - seconds * 0.5;
		setBill(total);
	}
	else
	{
		std::cout << "You don't have enough money" << std::endl;
	}
}

void Phone::serialize()
{
	std::cout << "Writing to file" << std::endl;
	std::ofstream writeStream;
	writeStream.open("Phones.txt", std::ios::app);
	if (writeStream.is_open() == false)
	{
		std::cout << "Error, file wasn't written";
	}
	else
	{
		writeStream << getModel() << "\n" << getNumber() << "\n" << getLastNuber() << "\n" << getBill() << "\n";
	}
	writeStream.close();
}

void Phone::deserialize()
{
	std::cout << "Reading file" << std::endl;
	std::string line;
	std::ifstream readStream("Phones.txt");
	if (!readStream.is_open())
	{
		std::cout << "Error, file wasn't read" << std::endl;
	}
	else
	{
		while (getline(readStream, line))
		{
			std::cout << line << std::endl;
		}
	}
	readStream.close();
}

void Phone::serialize(const std::string& filename)
{
	std::cout << "Writing to file" << std::endl;
	std::ofstream writeStream;
	writeStream.open(filename, std::ios::app);
	if (writeStream.is_open() == false) 
	{
		std::cout << "Error, file wasn't written";
	}
	else 
	{
		writeStream << getModel() << "\n" << getNumber() << "\n" << getLastNuber() << "\n" << getBill() << "\n";
	}
	writeStream.close();
}

void Phone::deserialize(const std::string& filename)
{
	std::cout << "Reading file" << std::endl;
	std::string line;
	std::ifstream readStream(filename);
	if (!readStream.is_open()) 
	{
		std::cout << "Error, file wasn't read" << std::endl;
	}
	else 
	{
		while (getline(readStream, line)) 
		{
			std::cout << line << std::endl;
		}
	}
	readStream.close();
}

void Phone::getInfo()
{
	std::cout << "Model: " << getModel() << std::endl;
	std::cout << "Phone number: " << getNumber() << std::endl;;
	std::cout << "Last number: " << getLastNuber() << std::endl;;
	std::cout << "Bill: " << getBill() << "\n" << std::endl;
}
