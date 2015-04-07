#include <iostream>


union Test
{
	unsigned long l;
	unsigned short s;
	unsigned char c;
};

union Address
{
	unsigned long addr_l;    // 32-bit
	unsigned char addr_c[4]; // 32-bit
};


struct UserInput
{
	/// Specifies what is the input type. Can be one of:
	/// 'i' - int
	/// 'd' - double
	/// 's' - string
	/// anything else - incorrect or uninitialized
	char InputType;

	union
	{
		int i;
		double d;
		char text[30];
	};
};


void PrintValues(Test* p)
{
	std::cout
		<< "Values:"
		<< "  t.l: 0x" << std::hex << p->l
		<< "  t.s: 0x" << std::hex << p->s
		<< "  t.c: 0x" << std::hex << (int)p->c
		<< "\n\n";
}


UserInput GetInput()
{
	UserInput ui;

	char c;
	std::cout << "What do you want to enter ([i]-int, [d]-double, [s]-string): ";
	std::cin >> c;

	switch (c)
	{
	case 'i':
		std::cout << "Enter an int: ";
		std::cin >> ui.i;
		ui.InputType = 'i';
		break;

	case 'd':
		std::cout << "Enter a double: ";
		std::cin >> ui.d;
		ui.InputType = 'd';
		break;

	case 's':
		std::cout << "Enter a string: ";
		std::cin.sync();
		std::cin.getline(ui.text, 30);
		ui.InputType = 's';
		break;

	default:
		std::cout << "Incorrect type!";
		ui.InputType = 0;
	}

	return ui;
}

int main()
{
	// Създаваме нова инстанция на Test
	Test t;

	// Извеждаме информация за размера на инстанцията
	// и за адресите на нейните членове
	std::cout
		<< "Size of Test union: " << sizeof(Test)
		<< "\nAddresses:"
		<< "\n  t  : 0x" << &t
		<< "\n  t.l: 0x" << &t.l
		<< "\n  t.s: 0x" << &t.s
		<< "\n  t.c: 0x" << std::hex << (void*)&t.c
		<< "\n\n";

	// По-долу променяме един от елементите на обединението
	// и проверяваме как се отразява това на останалите

	t.l = 0x12345678;
	PrintValues(&t); // Правилата за предаване на обединение
	                 // на функция са като тези за структура

	t.c = 0xFF;
	PrintValues(&t);


	// Примерът по-долу показва как можем да използваме
	// обединение, за да работим с една и съща информация
	// през различни типове
	Address a;

	a.addr_c[0] = 1;
	a.addr_c[1] = 0;
	a.addr_c[2] = 168;
	a.addr_c[3] = 192;

	std::cout
		<< "Address:\n   0x" << std::hex << a.addr_l
		<< std::dec
		<< "\n   " << (int)a.addr_c[3]
		<< '.'     << (int)a.addr_c[2]
		<< '.'     << (int)a.addr_c[1]
		<< '.'     << (int)a.addr_c[0]
		<< "\n\n";


	// Комбиниране на структура и обединение
	UserInput ui = GetInput();

	std::cout << "Let's see what has been entered...\n";

	switch (ui.InputType)
	{
	case 'i':
		std::cout << ui.i << " (int)";
		break;

	case 'd':
		std::cout << ui.d << " (double)";
		break;

	case 's':
		std::cout << ui.text << " (string)";
		break;

	default:
		std::cout << "Incorrect input!";
	}

	std::cout << "\n";

	return 0;
}