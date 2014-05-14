#include <iostream>

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
/// Представя рационално число
///
class Rational
{
public:
	/// Числителят на рационалното число
	int Numerator;

	/// Знаменателят на рационалното число
	int Denominator;

	/// Указва дали рационалното число трябва
	/// автоматично да се нормализира след всяка операция
	bool AutoNormalize;

	Rational();
	Rational(int, int, bool);
	Rational(bool);
	~Rational();

	bool IsValid() const;
	void Add(Rational &);

	void Print() const;
	void Input();

	void Normalize();

private:
	inline void PerformAutoNormalize();
};


///
/// Конструктор по подразбиране
///
Rational::Rational()
{
	std::cout << "  -> Entering Rational(), object at " << this << std::endl;

	this->Numerator = 0;
	this->Denominator = 0;
	this->AutoNormalize = true;

	PerformAutoNormalize();
}


///
/// Създава ново рационално число с числител Numerator и знаменател Denominator
///
Rational::Rational(int Numerator, int Denominator, bool AutoNormalize=true)
{
	std::cout << "  -> Entering Rational(" << Numerator << ", " << Denominator << "), object at " << this << std::endl;

	this->Numerator = Numerator;
	this->Denominator = Denominator;
	this->AutoNormalize = AutoNormalize;

	PerformAutoNormalize();
}


///
/// Създава празно рационално число, указвайки дали то да се нормализира автоматично
///
Rational::Rational(bool AutoNormalize)
{
	std::cout << "  -> Entering Rational(" << (AutoNormalize ? "true" : "false") << "), object at " << this << std::endl;

	this->Numerator = 0;
	this->Denominator = 0;
	this->AutoNormalize = AutoNormalize;
}

///
/// Деструктор
///
Rational::~Rational()
{
	std::cout << "  -> Entering ~Rational(), object at " << this << std::endl;
}


///
/// Връща true, ако данните в обекта са коректни.
///
/// Данните се считат за коректни, ако знаменателят е различен от нула.
///
bool Rational::IsValid() const
{
	return Denominator != 0;
}


///
/// Добавя стойността на рационалното число other към текущия обект.
///
void Rational::Add(Rational& other)
{
	Numerator = Numerator*other.Denominator + other.Numerator*Denominator;
	Denominator = Denominator * other.Denominator;

	PerformAutoNormalize();
}


///
/// Извежда рационалното число на екрана.
///
void Rational::Print() const
{
	std::cout << Numerator << "/" << Denominator;
}


///
/// Въвежда данните за рационалното число от STDIN.
///
void Rational::Input()
{
	std::cout << "Enter Numerator: ";
	std::cin >> Numerator;
	std::cout << "Enter Denominator: ";
	std::cin >> Denominator;

	PerformAutoNormalize();
}


///
/// Нормализира рационалното число
///
/// Нормализацията прави две неща:
///
/// 1. Коригира знаците на числителя и знаменателя:
/// 1.1 Ако числото е отрицателно, знакът минус се изнася в числителя
/// 1.2 Ако и числителят и знаменателят са отрицателни, те стават положителни
/// 
/// 2. Съкращава числителя и знаменателя на най-големия им общ делител
///
void Rational::Normalize()
{
	if( ! IsValid() )
		return;

	// Коригираме знаците
	if(Denominator < 0)
	{
		Numerator = -Numerator;
		Denominator = -Denominator;
	}

	// Съкращаваме числителя и знаменателя на най-големия им общ делител

	// Взимаме НОД по модул, за да не обърка знаците при делението
	int g = abs(gcd(Denominator, Numerator));

	Numerator /= g;
	Denominator /= g;
}


///
/// Нормализира числото, но само ако флагът AutoNormalize е вдигнат
///
inline void Rational::PerformAutoNormalize()
{
	if(AutoNormalize)
		Normalize();
}


int main()
{
	std::cout << "Entering main()\n";
	
	std::cout << "Constructing r1\n";
	Rational r1;

	std::cout << "Constructing a dynamic object\n";
	Rational *pSingle = new Rational();

	std::cout << "Constructing a dynamic array of five objects\n";
	Rational *pArray = new Rational[5];

	std::cout << "Destroy the dynamic object\n";
	delete pSingle;

	std::cout << "Destroy the dynamic array\n";
	delete [] pArray;

	std::cout << "Create and sum two rational numbers\n";
	Rational a(1,2);
	Rational b(2,4);
	
	std::cout << "  -> ";
	a.Print();
	std::cout << " + ";
	b.Print();
	std::cout << " = ";
	a.Add(b);
	a.Print();
	std::cout << "\n";

	std::cout << "Input a rational number from STDIN\n";
	Rational temp;
	temp.Input();
	std::cout << "You entered ";
	temp.Print();
	std::cout << std::endl;

	std::cout << "Leaving main()\n";

	return 0;
}