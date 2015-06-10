#include <iostream>
#include "Circle.h"


Circle::Circle()
{
	std::clog << "[Entering Circle::Circle()]\n";
	Radius = 0;
}


Circle::Circle(double Radius)
{
	std::clog
		<< "[Entering Circle::Circle("
		<< Radius
		<< ")]\n";

	this->Radius = Radius;
}

Circle::~Circle()
{
	std::clog << "[Entering Circle::~Circle()]\n";
}


double Circle::Area() const
{
	return 3.14 * Radius;
}


void Circle::Print() const
{
	std::cout << "A circle with radius " << Radius << std::endl;
}


void Circle::Input()
{
	std::cin.clear();
	std::cin.sync();

	std::cout << "Enter circle information below\n  Radius: ";
	std::cin >> Radius;
}