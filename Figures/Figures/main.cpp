#include <iostream>
#include <vector>

#include "Figure.h"

#include "StdinFigureFactory.h"
#include "FileFigureFactory.h"

/// Тип за вектор от фигури
typedef std::vector<Figure*> FIGVECTOR;

FigureFactory* ChooseFactory()
{
	char choice;

	std::cout
		<< "How do you want to enter the figures?"
		<< "\n   [k] - keyboard"
		<< "\n   [f] - read from file"
		<< "\n: ";
	std::cin >> choice;

	switch (choice)
	{
	case 'K':
	case 'k':
		return new StdinFigureFactory;

	case 'F':
	case'f':
		std::cin.clear();
		std::cin.sync();

		std::cout << "Filename: ";
		char buffer[_MAX_PATH];
		std::cin.getline(buffer, _MAX_PATH);

		return new FileFigureFactory(buffer);

	default:
		throw std::exception("Incorrect factory type");
	}
}

int main()
{
	FIGVECTOR figures;

	//
	// Създаваме подходяща фабрика (factory),
	// с която ще четем фигурите
	//
	FigureFactory* pFactory;
	
	try
	{
		pFactory = ChooseFactory();
	}
	catch (std::exception &e)
	{
		std::cerr
			<< "ERROR! Factory creation failed, reason: "
			<< e.what()
			<< "\n";
		return 1;
	}


	//
	// Въвеждаме фигурите
	//
	Figure* pFigure = NULL;

	do
	{
		try {
			pFigure = pFactory->CreateFigure();
			
			if(pFigure)
				figures.push_back(pFigure);
		}
		catch (std::bad_alloc& e)
		{
			std::cerr << "ERROR: Allocation failed! Reason: " << e.what() << "\n";
			break;
		}
		catch (std::exception& e)
		{
			std::cerr << "ERROR: Operation failed! Reason: " << e.what() << "\n";
		}

	} while (pFactory->CanCreate() && pFigure);


	//
	// Извеждаме въведените фигури и общата им площ
	//
	double area = 0;

	for (size_t i = 0; i < figures.size(); i++)
	{
		figures.at(i)->Print();
		area += figures.at(i)->Area();
	}

	std::cout << "Total figure area is " << area << std::endl;


	//
	// Освобождаваме заетата памет
	//
	for (size_t i = 0; i < figures.size(); i++)
	{
		delete figures.at(i);
	}

	delete pFactory;

	return 0;
}
