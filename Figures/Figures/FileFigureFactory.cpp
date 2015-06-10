#include "Figures.h"


FileFigureFactory::FileFigureFactory()
{
	Line = 0;
}

FileFigureFactory::FileFigureFactory(const char* FileName)
{
	OpenFile(FileName);
	Line = 1;
}

FileFigureFactory::~FileFigureFactory()
{
	CloseFile();
}

void FileFigureFactory::OpenFile(const char* FileName)
{
	InputFile.open(FileName);
	Line = 1;
}

void FileFigureFactory::CloseFile()
{
	InputFile.close();
}

bool FileFigureFactory::CanCreate()
{
	return InputFile.is_open() && InputFile.good();
}

Figure* FileFigureFactory::CreateFigure()
{
	char figureType[100];

	// Най-напред прочитаме типа на следващата фигура.
	// Ако той е валиден, прочитаме нейните данни и
	// създаваме съответния обект.

	InputFile >> figureType;

	if ( ! InputFile)
	{
		// Ако четенето пропадне (напр. стигнали сме до
		// края на файла), създаването на обекти приключва.

		return NULL;
	}

	if (strcmp(figureType, "Circle") == 0)
	{
		double Radius;
		InputFile >> Radius;

		if ( ! InputFile)
		{
			char message[100];
			sprintf_s(message, 100, "Error on line %u while reading circle data!", Line);
			throw std::exception(message);
		}

		Line++;

		return new Circle(Radius);
	}

	else if (strcmp(figureType, "Rectangle") == 0)
	{
		double Width, Height;
		InputFile >> Width >> Height;

		if ( ! InputFile)
		{
			char message[100];
			sprintf_s(message, 100, "Error on line %u while reading Rectangle data!", Line);
			throw std::exception(message);
		}

		Line++;

		return new Rectangle(Width, Height);
	}

	else
	{
		char message[130];
		sprintf_s(message, 130, "Unknown figure type \"%s\"", figureType);
		throw std::exception(message);
	}
}