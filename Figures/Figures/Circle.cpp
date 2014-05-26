#include <iostream>
#include "Circle.h"


Circle::Circle()
{
	std::cout << "[Entering Circle::Circle()]\n";
	Radius = 0;
}


Circle::~Circle()
{
	std::cout << "[Entering Circle::~Circle()]\n";
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
	std::cout << "Enter circle information below\n  Radius: ";
	std::cin >> Radius;
}