#include <iostream>
#include <vector>

#include "Circle.h"
#include "Rectangle.h"


/// Тип за вектор от фигури
typedef std::vector<Figure*> FIGVECTOR;


///
/// Създава нова фигура
///
Figure* CreateFigure()
{
	int choice;

	std::cout <<
		"What do you want to enter?\n"
		"  1 - Circle\n"
		"  2 - Rectangle\n"
		"Your choice: ";
	std::cin >> choice;

	switch (choice)
	{
	case 1:
		return new Circle();

	case 2:
		return new Rectangle();

	default:
		throw std::exception("Wrong input");
	}
}

int main()
{
	FIGVECTOR figures;

	// Въвеждаме фигурите
	char choice;

	do
	{
		try {
			Figure* pFigure = CreateFigure();
			pFigure->Input();
			figures.push_back(pFigure);
		}
		catch (std::bad_alloc& e)
		{
			std::cerr << "ERROR: Allocation failed! (reason: " << e.what() << ")\n";
			break;
		}
		catch (std::exception& e)
		{
			std::cerr << "ERROR: Operation failed! (reason: " << e.what() << ")\n";
		}

		std::cout << "Enter another figure (y/n): ";
		std::cin >> choice;
	
	} while (choice == 'y' || choice == 'Y');


	// Извеждаме въведените фигури и общата им площ
	double area = 0;

	for (size_t i = 0; i < figures.size(); i++)
	{
		figures.at(i)->Print();
		area += figures.at(i)->Area();
	}

	std::cout << "Total figure area is " << area << std::endl;


	// Освобождаваме заетата памет
	for (size_t i = 0; i < figures.size(); i++)
	{
		delete figures.at(i);
	}

	return 0;
}
