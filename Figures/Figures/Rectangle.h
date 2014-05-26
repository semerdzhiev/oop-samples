#pragma once

#include "Figure.h"

class Rectangle : 
	public Figure
{
private:
	double Width;
	double Height;

public:
	Rectangle();
	virtual ~Rectangle();

	virtual double Area() const;
	virtual void Print() const;
	virtual void Input();
};

