#pragma once

#include <iostream>

///
/// Шаблон за клас представящ масив
///
/// Ако типът на масива (ARRAY_TYPE) не е от
/// вградените атомарни типове, за него
/// трябва да са дефинирани и достъпни:
///    - Конструктор по подразбиране
///    - Оператор за присвояване
///
template <typename ARRAY_TYPE>
class Array
{
private:
	///
	/// Represents one of the array elements
	///
	class ElementProxy
	{
	private:
		Array* pArray;
		size_t ElementIndex;

	public:
		ElementProxy(Array* pArray, size_t ElementIndex);

		operator ARRAY_TYPE() const;
		ElementProxy& operator=(const ARRAY_TYPE);
	};

public:
	///
	/// Iterates the array sequentially
	/// starting from a specified initial position
	///
	class Iterator
	{
	protected:
		Array* pArray;
		size_t InitialPos;
		size_t CurrentPos;
		bool EndReached;
	public:
		Iterator(Array*, size_t);

	public:
		void Rewind();
		bool Next();
		bool IsOver() const;
		ARRAY_TYPE& Value();
		size_t Index() const;
	};

	///
	/// Iterates the array backwards
	/// starting from a specified initial position
	///
	class BackwardIterator : public Iterator
	{
	public:
		BackwardIterator(Array*, size_t);
		bool Next();
	};

	friend class Iterator;

private:
	ARRAY_TYPE *pArr;
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

	typename const Array<ARRAY_TYPE>::ElementProxy operator[](size_t) const;
	typename Array<ARRAY_TYPE>::ElementProxy operator[](size_t);

private:
	void CopyFrom(Array const &);

public:
	void SetSize(size_t NewSize);
	size_t GetSize() const;

	void SetAt(size_t index, ARRAY_TYPE const& Value);
	void SetAtAutoResize(size_t index, ARRAY_TYPE const& Value);
	ARRAY_TYPE GetAt(size_t index) const;

	void Release();

	typename Array<ARRAY_TYPE>::Iterator GetIterator();
	typename Array<ARRAY_TYPE>::BackwardIterator GetBackwardIterator();
};

///
/// Извежда съдържанието на масива
///
/// За да използваме тази функция, за типа ARRAY_TYPE
/// трябва да е предефиниран операторът:
/// std::ostream& operator<< (std::ostream&, ARRAY_TYPE const &)
///
template <typename ARRAY_TYPE>
std::ostream& operator<< (std::ostream&, Array<ARRAY_TYPE> const&);