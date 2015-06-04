#include "Box.h"

int main()
{
	Box<int> intBox;

	Box<char*> stringBox;  // OK, защото Box<char*> е пълна специализация
	                       // и няма нужда от инстанциране

	Box<long> longBox; // linker error: unresolved external

	return 0;
}
