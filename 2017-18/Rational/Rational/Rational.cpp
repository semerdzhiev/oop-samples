#include <stdexcept>

#include "Rational.h"


Rational::Rational()
{
}


Rational::~Rational()
{
}

int Rational::GetNumerator() const
{
	return Numerator;
}

int Rational::GetDenominator() const
{
	return Denominator;
}

void Rational::SetNumerator(int Value)
{
	Numerator = Value;
}

void Rational::SetDenominator(int Value)
{
	if (Value == 0)
		throw std::invalid_argument("Denominator cannot be zero");

	Denominator = Value;
}
