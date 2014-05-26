#pragma once

///
/// Базов клас за всички фигури
///
class Figure
{
public:
	Figure();
	virtual ~Figure();
	virtual double Area() const = 0;
	virtual void Print() const = 0;
	virtual void Input() = 0;
};

