#include <iostream>
#include "Rectangle.h"


Rectangle::Rectangle()
{
	std::cout << "[Entering Rectangle::Rectangle()]\n";
	Width = 0;
	Height = 0;
}


Rectangle::~Rectangle()
{
	std::cout << "[Entering Rectangle::~Rectangle()]\n";
}


double Rectangle::Area() const
{
	return Width * Height;
}


void Rectangle::Print() const
{
	std::cout
		<< "A rectangle with dimensions "
		<< Width
		<< "x"
		<< Height
		<< std::endl;
}


void Rectangle::Input()
{
	std::cout << "Enter rectangle information below\n  Width: ";
	std::cin >> Width;
	std::cout << "  Height: ";
	std::cin >> Height;
}