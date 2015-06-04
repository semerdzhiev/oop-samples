#pragma once


///
/// Шаблон за кутия, която съдържа един елемент от произволен тип
///
template <typename TYPE>
class Box
{
private:
	TYPE Stuff;

public:
	Box();
	Box(TYPE);

public:
	TYPE Peek() const;
	void Store(const TYPE);
};


///
/// Специализация на Box за символни низове
///
/// Членовете на специализацията могат да са различни
/// от тези на оригиналния шаблон.
///
template <>
class Box<char*>
{
private:
	char* Stuff;
	size_t Length;

public:
	Box();
	Box(char*);
	~Box();

	char* Peek() const;
	void Store(char*);
	size_t GetStringLength() const;
};