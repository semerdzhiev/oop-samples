#include <iostream>

///
/// Този клас се използва по два начина в програмата:
///	1. Хвърля се като изключение
/// 2. Негови обекти се създават в началото на всяка от извикваните функции.
///
/// Конструкторът и деструкторът са написани така, че да
/// извеждат информация, когато бъдат извиквани.
///
/// Целта е да може да се проследи жизненият цикъл на всеки от създадените обекти.
///
class Box {
private:
	/// Някакво съобщение, което описва създадения обект
	char Label[100];

public:
	Box(const char*);
	~Box();
	const char* GetLabel() const;
};


Box::Box(const char* Label)
{
	std::cout << "Entering Box(" << Label << ")\n";

	// Ако компилаторът не поддържа strcpy_s,
	// може да се използва код подобен на следния:
	// size_t charsToCopy = std::min((size_t)99, strlen(Label));
	// strncpy(this->Label, Label, charsToCopy);
	// this->Label[charsToCopy] = '\0';

	strcpy_s(this->Label, 100, Label);
}

Box::~Box()
{
	std::cout << "Entering ~Box(" << Label << ")\n";
}

const char* Box::GetLabel() const
{
	return Label;
}


///
/// Функция, която хвърля изключение.
///
void ThrowSomething()
{
	Box temp("Constructed by ThrowSomething()");

	int choice;

	std::cout
		<< "What do you want to throw today?\n"
		<< "  [1] char\n"
		<< "  [2] int\n"
		<< "  [3] unsigned int\n"
		<< "  [4] long\n"
		<< "  [5] float\n"
		<< "  [6] double\n"
		<< "  [7] std::exception object\n"
		<< "  [8] std::out_of_range object\n"
		<< "  [9] Box object (will be rethrown)\n"
		<< "Your choice: ";

	std::cin >> choice;

	switch(choice)
	{
	case 1:
		throw '!';

	case 2:
		throw 5;

	case 3:
		throw 5u;

	case 4:
		throw 5l;
	
	case 5:
		throw (float)5.5;

	case 6:
		throw (double)5.5;

	case 7:
		throw std::exception("Something happened!");

	case 8:
		throw std::out_of_range("Something is out of range!");

	case 9:
		throw Box("Thrown by ThrowSomething()");

	default:
		throw std::exception("Really? You failed to enter a number between 1 and 9?!");
	}

	std::cout << "Will this line ever be executed?\n";
}


///
/// Външна функция, която хвърля
///
void OuterFunction()
{
	Box temp("Constructed by OuterFunction()");

	try
	{
		ThrowSomething();
	}
	catch(int & e)
	{
		std::cout << "Caught an int: " << e << std::endl;
	}
	catch(double & e)
	{
		std::cout << "Caught a double: " << e << std::endl;
	}
	catch(Box & e)
	{
		std::cout << "Caught a Box: " << e.GetLabel() << ". Now throwing it again\n";
		throw;
	}
}


int main()
{
	Box temp("Constructed by main()");

	try {
		OuterFunction();
	}
	catch(std::exception & e)
	{
		std::cout << "Caught a std::exception: " << e.what() << std::endl;
	}
	catch(std::out_of_range & e)
	{
		std::cout << "Caught a std::out_of_range: " << e.what() << std::endl;
	}
	catch(Box & e)
	{
		std::cout << "Caught a Box: " << e.GetLabel() << std::endl;
	}
	catch(...)
	{
		std::cout << "Caught something that the rest have failed to catch... but what is it?\n";
	}
	return 0;
}