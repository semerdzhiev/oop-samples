#include <iostream>

#include "Array.h"

int main()
{
	// Тестваме Array::ElementProxy
	Array arr;

	arr[5] = 100;
	arr[10] = 100;

	std::cout << arr;

	const Array& ref = arr;

	std::cout << arr[5] << "\n";


	// Обхождаме масива с итератор и инициализираме елементите му.
	Array::Iterator it = arr.GetIterator();

	int counter = 0;

	while (!it.IsOver())
	{
		it.Value() = counter++;
		it.Next();
	}


	// Използваме Array::BackwardIterator,
	// за да изведем елементите на масива в обратен ред
	Array::BackwardIterator bit = arr.GetBackwardIterator();

	std::cout << "Array contents:";

	while (!bit.IsOver())
	{
		std::cout << "\n[" << bit.Index() << "] = " << bit.Value();
		bit.Next();
	}

	std::cout << "\n\n";


	return 0;
}