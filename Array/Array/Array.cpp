#include <algorithm>
#include <iostream>

#include "Array.h"


///
/// Създава празен масив
///
Array::Array()
{
	pArr = NULL;
	Size = 0;
}


///
/// Създава нов масив с размер Size
///
Array::Array(size_t Size)
{
	pArr = NULL;
	Size = 0;

	SetSize(Size);
}


///
/// Copy-constructor
///
Array::Array(Array const & other)
{
	pArr = NULL;
	Size = 0;

	CopyFrom(other);
}


///
/// Деструктор
///
Array::~Array()
{
	Release();
}


///
/// Оператор за присвояване.
///
Array& Array::operator=(Array const & other)
{
	if (this != &other)
	{
		CopyFrom(other);
	}

	return *this;
}


///
/// Променя масива така, че да бъде копие на other.
///
/// Ако функцията приключи успешно, масивът ще бъде
/// със същия размер като other и ще съдържа
/// идентични елементи.
///
/// Ако функцията не успее, съдържанието на масива
/// остава непроменено (както е било преди извикването ѝ).
///
/// \exception std::bad_alloc
///    Ако функцията е успее да задели памет за копирането
///
void Array::CopyFrom(Array const & other)
{
	SetSize(other.GetSize());

	for (size_t i = 0; i < other.Size; i++)
		pArr[i] = other.pArr[i];
}


///
/// Променя размера на масива
///
/// \param NewSize
///    Новият размер на масива. Може да бъде по-голям
///    или по-малък от настоящия.
///
/// Нека старият размер на масива е S, а новият - N.
/// Ако S <= N, елементите на масива до позиция
/// S-1 остават същите, а тези от S до N са неопределени.
/// Ако S > N, в масива се запазват само старите елементи
/// от позиции 0 до N-1, а останалите елементи ще се изгубят.
///
/// Ако функцията не успее, съдържанието на масива остава непроменено.
///
/// \throws std::bad_alloc
///		Ако заделянето на памет за масива не успее.
///
void Array::SetSize(size_t NewSize)
{
	int *pNewArray = new int[NewSize];

	size_t ElementsToCopy = std::min(Size, NewSize);

	for (size_t i = 0; i < ElementsToCopy; i++)
	{
		pNewArray[i] = pArr[i];
	}

	delete[] pArr;

	pArr = pNewArray;
	Size = NewSize;
}


///
/// Връща броя на елементите в масива
///
size_t Array::GetSize() const
{
	return Size;
}


///
/// Освобождава паметта заета от масива
///
/// След изпълнението на тази операция, масивът
/// ще бъде празен (ще съдържа нула елементи).
///
void Array::Release()
{
	delete[] pArr;

	pArr = NULL;
	Size = 0;
}


///
/// Променя елемента, който се намира на позиция
/// index в масива като го прави равен на Value
///
/// \exception out_of_range
///		Ако index излиза от размерите на масива.
///
void Array::SetAt(size_t index, int Value)
{
	if (index >= Size)
		throw std::out_of_range("Invalid index");

	pArr[index] = Value;
}


///
/// Връща елемента, който се намира на позиция index в масива.
///
/// \exception out_of_range
///		Ако index излиза от размерите на масива.
///
int Array::GetAt(size_t index) const
{
	if (index >= Size)
		throw std::out_of_range("Invalid index");

	return pArr[index];
}


///
/// Конкатенира елементите на масива other
/// към настоящия обект.
///
Array& Array::operator+=(Array const & other)
{
	size_t OldSize = GetSize();

	SetSize(GetSize() + other.GetSize());

	for (size_t i = 0; i < other.GetSize(); i++)
	{
		pArr[i + OldSize] = other.pArr[i];
	}

	return *this;
}


///
/// Конкатенира два масива и връща резултата
/// като нов обект.
///
Array Array::operator+(Array const &other) const
{
	Array result(*this);
	
	result += other;
	
	return result;
}


///
/// Връща елемента на масива, който се намира на позиция index
///
int& Array::operator[](size_t index)
{
	if (index >= Size)
		throw std::out_of_range("Invalid index");

	return pArr[index];
}


///
/// Извежда съдържанието на масива arr в потока out
///
std::ostream& operator<< (std::ostream& out, Array const& arr)
{
	out << "Array object at 0x" << &arr;

	for (size_t i = 0; i < arr.GetSize(); i++)
	{
		out << "\n   [" << i << "] = " << arr.GetAt(i);
	}

	out << "\n";

	return out;
}
