#include <iostream>
#include <time.h>

///
/// Клас, който брои колко негови обекта са били създадени
/// в рамките на изпълнението на програмата и колко обекта
/// съществуват към дадения момент.
///
class Counter
{
private:
	
	/// Брой на съществуващите към дадения момент обекти
	static int ExistingObjectsCount;
	
	/// Брой на създадените в рамките на изпълнението на програмата обекти
	static int ObjectsCreatedCount;

public:
	Counter();
	~Counter();

	static int GetExistingObjectsCount();
	static int GetObjectsCreatedCount();
};

int Counter::ObjectsCreatedCount = 0;
int Counter::ExistingObjectsCount = 0;


///
/// Конструктор по подразбиране
///
Counter::Counter()
{
	ExistingObjectsCount++;
	ObjectsCreatedCount++;
}


///
/// Деструктор
///
Counter::~Counter()
{
	ExistingObjectsCount--;
}


///
/// Връща броя на съществуващите към момента на извикването
/// на функцията обекти от тип Counter
///
int Counter::GetExistingObjectsCount()
{
	return ExistingObjectsCount;
}


///
/// Връща броя на създадените до момента на извикването
/// на функцията обекти от тип Counter
///
int Counter::GetObjectsCreatedCount()
{
	return ObjectsCreatedCount;
}


int main()
{
	srand((unsigned)time(NULL));

	// Генерира псведослучайно число между 1 и 10
	int callCount = rand() % 10 + 1;

	while(callCount-- > 0)
	{
		Counter temp;
		std::cout << "Counter objects: "
				  << Counter::GetExistingObjectsCount()
				  << " currently existing and a total of "
				  << Counter::GetObjectsCreatedCount()
				  << " created\n";
	}	

	return 0;
}