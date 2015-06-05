#pragma once

#include <iostream>

class Array
{
	class ElementProxy
	{
	private:
		Array* pArray;
		size_t ElementIndex;

	public:
		ElementProxy(Array* pArray, size_t ElementIndex);

		operator int() const;
		ElementProxy& operator=(const int);
	};

private:
	int *pArr;
	size_t Size;

public:
	Array();
	Array(size_t Size);
	Array(Array const &);
	~Array();
	Array& operator=(Array const &);

public:
	Array& operator+=(Array const &);
	Array operator+(Array const &) const;

	const ElementProxy operator[](size_t) const;
	ElementProxy operator[](size_t);

private:
	void CopyFrom(Array const &);

public:
	void SetSize(size_t NewSize);
	size_t GetSize() const;

	void SetAt(size_t index, int Value);
	void SetAtAutoResize(size_t index, int Value);
	int GetAt(size_t index) const;

	void Release();
};

std::ostream& operator<< (std::ostream&, Array const&);