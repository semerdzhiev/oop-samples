#include <iostream>
#include <time.h>

///
/// Функция, която брои колко пъти е била извикана
///
void CountCalls()
{
	static int callCount = 0;

	callCount++;

	std::cout << "CountCalls() was called " << callCount << " times\n";
}


int main()
{
	srand((unsigned)time(NULL));

	// Генерира псведослучайно число между 1 и 10
	int callCount = rand() % 10 + 1;

	while(callCount-- > 0)
	{
		CountCalls();
	}
}