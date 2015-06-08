#include <iostream>
#include <string>

///
/// Шаблон на функция сравняваща два произволни елемента
/// по техните стойности
///
template <typename TYPE>
TYPE minByValue(TYPE a, TYPE b)
{
	return a < b ? a : b;
}


///
/// Частична специализация (partial specialization)
/// на шаблона minByValue за указатели.
///
/// Функцията сравнява стойностите към които сочат указателите,
/// а не съхранените в тях адреси.
///
template <typename TYPE>
TYPE* minByValue(TYPE* a, TYPE* b)
{
	return *a < *b ? a : b;
}


///
/// Специализация на шаблона minByValue за символни низове
///
template <>
const char* minByValue(const char* a, const char* b)
{
	return (strcmp(a, b) < 0) ? a : b;
}


/// Извежда на екрана израза x и неговата стойност
#define PRINT(x) std::cout << #x " = " << (x) << "\n";

int main()
{
	int a = 4;
	int b = 5;

	char str1[] = "ab";
	char str2[] = "az";

	PRINT(a);
	PRINT(b);

	PRINT(&a);
	PRINT(&b);

	PRINT(minByValue(a, b));

	PRINT(minByValue(&a, &b));

	PRINT(minByValue("ab", "az"));

	PRINT(minByValue(str1, str2));

	return 0;
}
