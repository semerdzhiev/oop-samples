#include <iostream>

///
/// Представя рационално число
///
struct Rational
{
	/// Числителят на рационалното число
	int Numerator;

	/// Знаменателят на рационалното число
	int Denominator;
};


///
/// Инициализира една инстанция на рационално число
///
void Init(Rational& r, int Numerator=0, int Denominator=0)
{
	r.Numerator = Numerator;
	r.Denominator = Denominator;	
}


///
/// Проверява дали дадена инстанация на Rational съдържа коректни данни.
///
/// Функцията проверява дали знаменателят на числото е различен от нула.
///
bool IsValid(const Rational& r)
{
	return r.Denominator != 0;
}


///
/// Събира две рационални числа и връща резултата
///
/// \return
///		Ново рационално число, която съдържа сумата или
///		0/0, ако някое от r1 и r2 не е валидно рационално число.
///
Rational Sum(const Rational& r1, const Rational& r2)
{
	Rational result;

	Init(result);
	
	if(IsValid(r1) && IsValid(r2))
	{
		result.Numerator = r1.Numerator*r2.Denominator + r2.Numerator*r1.Denominator;
		result.Denominator = r1.Denominator * r2.Denominator;
	}

	return result;
}


///
/// Намира най-големия общ делител на две цели числа
///
int gcd(int a, int b)
{
	int temp;

	while (b != 0)
	{
		temp = a % b;

		a = b;
		b = temp;
	}
	
	return a;
}


///
/// Нормализира дадено рационално число
///
/// Нормализацията прави две неща:
///
/// 1. Коригира знаците на числителя и знаменателя:
/// 1.1 Ако числото е отрицателно, знакът минус се изнася в числителя
/// 1.2 Ако и числителят и знаменателят са отрицателни, те стават положителни
/// 
/// 2. Съкращава числителя и знаменателя на най-големия им общ делител
///
void Normalize(Rational& r)
{
	if( ! IsValid(r) )
		return;

	// Коригираме знаците
	if(r.Denominator < 0)
	{
		r.Numerator = -r.Numerator;
		r.Denominator = - r.Denominator;
	}

	// Съкращаваме числителя и знаменателя на най-големия им общ делител

	// Взимаме НОД по модул, за да не обърка знаците при делението
	int g = abs(gcd(r.Denominator, r.Numerator));

	r.Numerator /= g;
	r.Denominator /= g;
}


///
/// Извежда рационално число на екрана
///
void Print(Rational r)
{
	std::cout << r.Numerator << "/" << r.Denominator;
}


int main()
{
	// Създаваме три рационални числа
	Rational r1, r2, r3;

	// Инициализираме числата с начални стойности
	Init(r1, 1, 3);
	Init(r2, 2, 4);
	Init(r3);

	// Ивеждаме числата на екрана
	std::cout << "r1 = ";
	Print(r1);
	std::cout << "\nr2 = ";
	Print(r2);
	std::cout << "\nr3 = ";
	Print(r3);
	std::cout << std::endl;

	// Събираме две числа
	r3 = Sum(r2, r2);

	Print(r2);
	std::cout << " + ";
	Print(r2);
	std::cout << " = ";
	Print(r3);
	std::cout << std::endl;

	// Нормализираме резултата
	Normalize(r3);
	std::cout << "Normalized r3: ";
	Print(r3);
	std::cout << std::endl;
}