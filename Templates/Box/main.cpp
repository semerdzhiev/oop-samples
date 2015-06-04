#include "Box.h"

int main()
{
	Box<int> intBox;
	Box<char*> stringBox;

	intBox.Store(10);
	stringBox.Store("1234567890");

	return 0;
}
