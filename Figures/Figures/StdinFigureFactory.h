#pragma once

#include "FigureFactory.h"

class StdinFigureFactory : public FigureFactory
{
private:
	bool InputIsOver;

public:
	StdinFigureFactory();
	virtual ~StdinFigureFactory();

	virtual bool CanCreate();
	virtual Figure* CreateFigure();
};

