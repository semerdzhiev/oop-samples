/*
	Заделянето на памет в този пример се прави с nothrow,
	например:
	
	int** ppBuffer = new (std::nothrow) int* [Rows];

	В този случай, ако заделянето е неуспешно, new не хвърля
	изключение, а вместо това връща NULL
*/

#include <iostream>
#include <assert.h>

///
///	Освобождава паметта заета от двумерен масив,
/// който е бил заделен с Allocate().
///
void Free(int** ppArray, size_t Rows)
{
	assert(ppArray != NULL);

	for(size_t i = 0; i < Rows; i++)
	{
		delete [] ppArray[i];
	}

	delete [] ppArray;
}


///
///	Заделя двумерен масив
///
/// \return
///		Указател към новозаделения масив или
///		NULL, ако функцията не успее да задели масива
///
int** Allocate(size_t Rows, size_t Cols)
{
	int** ppBuffer = new (std::nothrow) int* [Rows];

	if( ! ppBuffer)
		return NULL;

	for(size_t i = 0; i < Rows; i++)
	{
		ppBuffer[i] = new (std::nothrow) int [Cols];

		if( ! ppBuffer[i])
		{
			Free(ppBuffer, i);
			return NULL;
		}
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

	int **ppArray = Allocate(Rows, Cols);

	if( ! ppArray)
	{
		std::cerr << "Allocation failed!";
		return 1;
	}

	// Тук можем да използваме масива за нещо полезно

	Free(ppArray, Rows);

	return 0;
}