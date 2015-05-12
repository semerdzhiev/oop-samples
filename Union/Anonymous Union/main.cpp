#include <iostream>

struct Test
{
	unsigned int n1;

	union {
		unsigned int n2;
		unsigned short s;
	};
};

int main()
{
	union
	{
		unsigned int n;
		unsigned short s;
	};

	n = 0x12345678;

	std::cout
		<< std::hex
		<< "n = 0x"   << n << " (@ 0x" << &n << ")"
		<< "\ns = 0x" << s << " (@ 0x" << &s << ")"
		<< std::endl;
	
	Test t;

	t.n1 = 0x12345678;
	t.n2 = 0xAABBCCDD;

	std::cout
		<< std::hex
		<< "\nt.n1 = 0x" << t.n1 << " (@ 0x" << &t.n1 << ")"
		<< "\nt.n2 = 0x" << t.n2 << " (@ 0x" << &t.n2 << ")"
		<< "\n t.s = 0x" << t.s  << " (@ 0x" << &t.s << ")"
		<< std::endl;

	return 0;
}