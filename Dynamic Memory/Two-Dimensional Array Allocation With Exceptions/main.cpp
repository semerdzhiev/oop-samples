/*
	
	За разлика от другия пример, в който при заделянето на памет
	с new се използва nothrow, тук се използва механизмът на изключенията.

	Забележете, че обработването на изключения се случва на две нива.
	1. Най-напред функцията Allocate прихваща изключенията хвърлени от new.
	Ако някое от заделянията не успее, тя почиства след себе си
	(с обръщение към Free) и след това отново хвърля полученото изключение
	(throw без операнд).
	2. Повторно хвърленото изключение се хваща от потребителя (този,
	който използва Allocate). Така той може да разбере, че заделянето е било
	неуспешно и може да предприеме нужните мерки.

	Употреба:
		За да се провери поведението на програмата при грешка
		може да се въведат големи числа за брой редове и колони,
		например:

		Enter Rows: 111111111
		Enter Cols: 111111111

*/

#include <iostream>
#include <assert.h>

///
///	Освобождава паметта заета от двумерен масив,
/// който е бил заделен с Allocate().
///
void Free(int** ppArray, size_t Rows)
{
	if(ppArray != NULL)
	{
		for(size_t i = 0; i < Rows; i++)
		{
			delete [] ppArray[i];
		}

		delete [] ppArray;
	}
}


///
///	Заделя двумерен масив
///
/// \return
///		Указател към новозаделения масив или
///		NULL, ако функцията не успее да задели масива
///
/// \exception std::bad_alloc
///		Ако заделянето на памет е неуспешно.
///
/// В тялото на функцията, след всяко от заделянията на памет с new
/// не се прави проверка за == NULL, защото ако new не успее,
/// ще бъде хвърлено изключение от тип std::bad_alloc и така и
/// няма да се стигне до стоящия след него код
/// 
int** Allocate(size_t Rows, size_t Cols)
{
	// Декларираме променливите извън try блока,
	// за да могат да бъдат използвани в catch
	int** ppBuffer = NULL;
	size_t i = 0;

	try
	{
		ppBuffer = new int* [Rows];

		for(i = 0; i < Rows; i++)
		{
			ppBuffer[i] = new int [Cols];
		}
	}
	catch(std::bad_alloc&)
	{
		Free(ppBuffer, i);
		
		throw; // отново хвърляме полученото изключение
	}

	return ppBuffer;
}


int main()
{
	size_t Rows, Cols;

	std::cout << "Enter Rows: ";
	std::cin >> Rows;

	std::cout << "Enter Cols: ";
	std::cin >> Cols;

	int** ppArray = NULL;
	
	try
	{
		ppArray = Allocate(Rows, Cols);
	}
	catch(std::bad_alloc& e)
	{
		std::cerr << "ERROR: Allocation failed! (" << e.what() << ")\n";
		return 1;
	}

	// Тук можем да използваме масива за нещо полезно

	Free(ppArray, Rows);
	ppArray = NULL;

	// Продължаваме с програмата ...

	return 0;
}