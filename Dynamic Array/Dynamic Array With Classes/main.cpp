#include <iostream>
#include <time.h>

///
/// Представя динамичен масив
///
class DynamicArray
{
private:
	/// Данните на масива
	int *pData;

	/// Размер на заделената памет за масива
	size_t AllocatedSize;
	
	/// Брой на използваните клетки от масива
	size_t Length;

public:
	DynamicArray();
	DynamicArray(DynamicArray const &);
	DynamicArray& operator=(DynamicArray const &);
	~DynamicArray();

public:
	void Free();
	
	void Add(int Element);

	size_t GetAllocatedSize() const;
	size_t GetLength() const;
	int GetAt(size_t) const;

	void Print() const;

private:
	void Reallocate(size_t NewSize);
	void CopyFrom(DynamicArray const &);
};


///
/// Създава нов динамичен масив
///
/// След инициализацията масивът е празен
/// (за него не е заделена динамична памет)
///
DynamicArray::DynamicArray()
{
	std::cout
		<< " -> [" << this << "] "
		<< "Entering DynamicArray()\n";

	pData = NULL;
	AllocatedSize = 0;
	Length = 0;
}


///
/// Конструктор за копиране (copy constructor)
///
DynamicArray::DynamicArray(DynamicArray const & other)
{
	std::cout
		<< " -> [" << this << "] "
		<< "Entering DynamicArray(DynamicArray const &)\n";

	CopyFrom(other);
}



///
/// Оператор за присвояване (assignment operator)
///
DynamicArray& DynamicArray::operator=(DynamicArray const & other)
{
	if(this != &other)
	{
		Free();
		CopyFrom(other);
	}

	return *this;
}


///
/// Деструктор
///
DynamicArray::~DynamicArray()
{
	std::cout
		<< " -> [" << this << "] "
		<< "Entering ~DynamicArray()\n";

	Free();
}


///
/// Копира данните от масива other в текущия обект
///
/// Функцията предполага, че масивът е празен.
/// Те не извършва действия за освобождаване на заетата памет.
/// Ако е нужно, преди нейното извикване трябва да се направи
/// обръщение към Free().
///
void DynamicArray::CopyFrom(DynamicArray const & other)
{
	pData = new int[other.AllocatedSize];

	for(size_t i = 0; i < other.Length; i++)
		pData[i] = other.pData[i];

	AllocatedSize = other.AllocatedSize;
	Length = other.Length;
}


///
/// Освобождава паметта заета от динамичния масив
///
void DynamicArray::Free()
{
	delete [] pData;
	pData = NULL;
	AllocatedSize = 0;
	Length = 0;
}


///
/// Преоразмерява динамичния масив, така че той да съдържа
/// NewSize елемента.
///
/// Ако NewSize е по-малко от текущия размер на масива,
/// елементите с индекси >= NewSize се губят.
///
void DynamicArray::Reallocate(size_t NewSize)
{
	std::cout
		<< " -> [" << this << "] "
		<< "Reallocating " << AllocatedSize << " -> " << NewSize << "\n";

	int* pTemp = new int[NewSize];

	// колко елемента ще бъдат копирани
	size_t limit = std::min(AllocatedSize, NewSize);

	for(size_t i = 0; i < limit; i++)
		pTemp[i] = pData[i];

	delete [] pData;

	pData = pTemp;
	AllocatedSize = NewSize;
}


///
/// Добавя нов елемент в динамичния масив
///
/// Новият елемент се добавя в края на масива.
///
void DynamicArray::Add(int Element)
{
	if(Length >= AllocatedSize)
	{
		size_t NewSize = (AllocatedSize == 0 ? 2 : AllocatedSize*2);
		
		Reallocate(NewSize);
	}

	pData[Length++] = Element;
}


///
/// Връща размера на заетата от масива памет
///
size_t DynamicArray::GetAllocatedSize() const
{
	return AllocatedSize;
}


///
/// Връща броя на елементите в масива
///
size_t DynamicArray::GetLength() const
{
	return Length;
}


///
/// Връща елемента намиращ се на позиция index в масива
///
int DynamicArray::GetAt(size_t index) const
{
	return pData[index];
}


///
/// Извежда информация за масива в STDOUT
///
void DynamicArray::Print() const
{
	std::cout
		<< "Dynamic Array at 0x" << this
		<< ", buffer at 0x"      << pData
		<< ", size ("            << Length
		<< " / "                 << AllocatedSize
		<< ")\n";
}


///
/// Генерира нов масив - конкатенация на масивите lhs и rhs
///
DynamicArray operator+ (DynamicArray const& lhs, DynamicArray const& rhs)
{
	DynamicArray temp(lhs);

	for(size_t i = 0; i < rhs.GetLength(); i++)
	{
		temp.Add(rhs.GetAt(i));
	}

	return temp;
}


int main()
{
	DynamicArray da;

	//
	// 1: Добавяме елементи в масива
	//

	// Брой на елементите, които ще бъдат добавени
	const size_t ELEMENTS_COUNT = 2000;

	time_t then = time(NULL);

	for(int i = 0; i < ELEMENTS_COUNT; i++)
	{
		da.Add(i);
	}

	time_t now = time(NULL);

	std::cout << "Filling the array with " << ELEMENTS_COUNT
		      << " element(s) took " << (now - then) << " second(s)\n";


	da.Print();

	//
	// 2: Оператор за събиране
	//
	DynamicArray test1;

	test1 = da + da;

	test1.Print();


	//
	// 3: Оператор за присвояване
	//
	DynamicArray  test2(da);

	test2.Print();

	return 0;
}

