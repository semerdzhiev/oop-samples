#include <iostream>

#include "Array.h"

int main()
{
	Array arr;

	arr[5] = 100;
	arr[10] = 100;

	std::cout << arr;

	const Array& ref = arr;

	std::cout << arr[5] << "\n";

	return 0;
}