#pragma once

#include "FigureFactory.h"

#include <fstream>

class FileFigureFactory : public FigureFactory
{
private:
	std::ifstream InputFile;
	size_t Line;

public:
	FileFigureFactory();
	FileFigureFactory(const char*);
	~FileFigureFactory();

	void OpenFile(const char*);
	void CloseFile();
	
	virtual bool CanCreate();
	virtual Figure* CreateFigure();

private:
	Figure* ReadCircle();
	Figure* ReadRectangle();
};

