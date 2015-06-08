#pragma once

class Array
{
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
	int& operator[](size_t);

private:
	void CopyFrom(Array const &);

public:
	void SetSize(size_t NewSize);
	size_t GetSize() const;

	void SetAt(size_t index, int Value);
	int GetAt(size_t index) const;

	void Release();
};

std::ostream& operator<< (std::ostream&, Array const&);

