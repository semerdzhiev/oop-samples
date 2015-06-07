#include <iostream>

#include "Array.h"

int main()
{
	Array arr1, arr2;

	arr1.SetSize(5);
	arr2.SetSize(5);

	for (size_t i = 0; i < 5; i++)
	{
		arr1.SetAt(i, i);
		arr2[i] = i + 5;
	}

	std::cout << arr1 << arr2;

	arr1 += arr2;

	std::cout << arr1;

	return 0;
}