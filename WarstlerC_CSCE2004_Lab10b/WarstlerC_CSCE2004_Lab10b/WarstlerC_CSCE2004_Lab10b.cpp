// WarstlerC_CSCE2004_Lab10b.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include <iostream>
using namespace std;

// Interface for Temperature class
//--------------------------------
const double ABSOLUTE_ZERO = -273.15;
const double SUN_CORE_TEMP = 15710000;
class Temperature
{
public:
	Temperature();
	Temperature(const Temperature& Temp);
	~Temperature();
	double getCelsius() const;
	double getFahrenheit() const;
	void setCelsius(double Temp);
	void setFahrenheit(double Temp);

private:
	double CelsiusTemperature;
};

// Implementation of Temperature class
//-----------------------------------
Temperature::Temperature()
{
	CelsiusTemperature = 0;
}

Temperature::Temperature(const Temperature& Temp)
{
	CelsiusTemperature = Temp.CelsiusTemperature;
}

Temperature::~Temperature()
{
}

double Temperature::getCelsius() const
{
	return CelsiusTemperature;
}

double Temperature::getFahrenheit() const
{
	return 9.0 * CelsiusTemperature / 5.0 + 32.0;
}

void Temperature::setCelsius(double Temp)
{
	CelsiusTemperature = Temp;
	if (CelsiusTemperature < ABSOLUTE_ZERO)
		CelsiusTemperature = ABSOLUTE_ZERO;
	if (CelsiusTemperature > SUN_CORE_TEMP)
		CelsiusTemperature = SUN_CORE_TEMP;
}

void Temperature::setFahrenheit(double Temp)
{
	CelsiusTemperature = (Temp - 32.0) * 5.0 / 9.0;
	if (CelsiusTemperature < ABSOLUTE_ZERO)
		CelsiusTemperature = ABSOLUTE_ZERO;
	if (CelsiusTemperature > SUN_CORE_TEMP)
		CelsiusTemperature = SUN_CORE_TEMP;
}

int main()
{

	Temperature freezing;
	Temperature boiling;
	Temperature coldcold;
	Temperature hothot;
	freezing.setCelsius(0);
	boiling.setCelsius(100);
	coldcold.setCelsius(-500);
	hothot.setCelsius(20000000);
	cout << "freezing: " << freezing.getFahrenheit() << "F\n";
	cout << "boiling: " << boiling.getFahrenheit() << "F\n";
	cout << "coldcold: " << coldcold.getCelsius() << "C\n";
	cout << "hothot: " << hothot.getCelsius() << "C\n";
	return 0;
}