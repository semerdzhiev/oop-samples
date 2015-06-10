#pragma once

#include "Figure.h"

class FigureFactory
{
public:
	FigureFactory();
	virtual ~FigureFactory();

public:
	///
	/// Връща true, ако фабриката може да създава обекти
	///
	virtual bool CanCreate() = 0;

	///
	/// Връща нов Figure обект или NULL, ако създаването
	/// на нов обект не е възможно
	///
	virtual Figure* CreateFigure() = 0;
};

