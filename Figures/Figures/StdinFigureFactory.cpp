#include <iostream>

#include "Figures.h"


StdinFigureFactory::StdinFigureFactory()
{
	InputIsOver = false;
}


StdinFigureFactory::~StdinFigureFactory()
{
}


bool StdinFigureFactory::CanCreate()
{
	if (! InputIsOver)
	{
		char choice;

		std::cout << "Enter another figure (y/n): ";
		std::cin >> choice;

		InputIsOver = choice != 'y' && choice != 'Y';
	}

	return ! InputIsOver;
}


Figure* StdinFigureFactory::CreateFigure()
{
	if (InputIsOver)
		return NULL;

	int choice;

	std::cin.clear();
	std::cin.sync();

	std::cout <<
		"What do you want to enter?\n"
		"  1 - Circle\n"
		"  2 - Rectangle\n"
		"Your choice: ";
	std::cin >> choice;
	
	Figure * pFigure = NULL;
	
	switch (choice)
	{
	case 1:
		pFigure = new Circle();
		break;

	case 2:
		pFigure = new Rectangle();
		break;

	default:
		throw std::exception("Wrong input");
	}

	pFigure->Input();

	return pFigure;
}
