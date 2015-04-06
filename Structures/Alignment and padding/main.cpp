#include <iostream>
#include <fstream>

struct Test
{
	// За упражнение: опитайте да разместите полетата в структурата и
	// вижте как това ще се отрази върху нейния размер
	char c1;
	short s;
	char c2;
	long l;
	unsigned char c3;
};


// Задава начални стойности на полетата в структурата
void Init(Test* p)
{
	p->c1 = 0x01;
	p->s = 0x1234;
	p->c2 = 0x02;
	p->l = 0x12345678;
	p->c3 = 0x03;
}


// Записва съдържанието на структура в текстов файл
void SaveToTextFile(Test* p, std::ofstream& file)
{
	file
		<< p->c1 << " "
		<< p->s  << " "
		<< p->c2 << " "
		<< p->l  << " "
		<< p->c3 << "\n";
}


// Извежда информация за offset-а на едно от полетата в структурата
#define FIELD_INFO(field) std::cout << "    " #field ": offset=" << offsetof(Test, field) << "\n";


int main()
{
	// Извеждаме информация за структурата
	std::cout << "Size of Test: " << sizeof(Test) << std::endl;
	FIELD_INFO(c1);
	FIELD_INFO(s);
	FIELD_INFO(c2);
	FIELD_INFO(l);
	FIELD_INFO(c3);

	
	// Създаваме и инициализираме нова инстанция на структурата
	Test instance;
	Init(&instance);

	// За упражнение: Стартирайте програмата през debugger, намерете
	// структурата instance в паметта и разгледайте как са разположени
	// нейните членове.

	// Създаваме и инициализираме масив от структури
	Test arr[5];

	for (int i = 0; i < 5; i++)
		Init(&arr[i]);

	// За упражнение: Както и за instance по-горе, намерете масива в паметта и
	// вижте как са разположени неговите елементи в паметта.


	// Правилата на указателната аритметика остават същите
	Test* p = arr;
	std::cout << "First element at 0x" << p << ", second element at 0x" << (p + 1) << "\n";

	return 0;
}