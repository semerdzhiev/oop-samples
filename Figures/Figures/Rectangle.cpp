#include <iostream>
#include "Rectangle.h"


Rectangle::Rectangle()
{
	std::clog << "[Entering Rectangle::Rectangle()]\n";
	Width = 0;
	Height = 0;
}


Rectangle::Rectangle(double Width, double Height)
{
	std::clog
		<< "[Entering Rectangle::Rectangle("
		<< Width
		<< ", "
		<< Height
		<< ")]\n";

	this->Width = Width;
	this->Height = Height;
}


Rectangle::~Rectangle()
{
	std::clog << "[Entering Rectangle::~Rectangle()]\n";
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
	std::cin.clear();
	std::cin.sync();

	std::cout << "Enter rectangle information below\n  Width: ";
	std::cin >> Width;
	std::cout << "  Height: ";
	std::cin >> Height;
}