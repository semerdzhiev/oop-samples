#pragma once

class Rational
{
private:
	int Numerator;
	int Denominator;

public:
	Rational();
	~Rational();

public:
	int GetNumerator() const;
	int GetDenominator() const;

	void SetNumerator(int Value);
	void SetDenominator(int Value);
};

