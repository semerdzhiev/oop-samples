#include <iostream>
#include <iomanip>

#include "StudentCollection.h"

int main()
{
	std::cout << "\n=== Entering main()\n";

	std::cout << "\n=== Student object 1\n";
	Student s1(12345, "John Smith", "+359123456");
	s1.Print();

	std::cout << "\n=== Student object 2\n";
	Student s2(s1);
	s2.Print();

	std::cout << "\n=== Student object 3\n";
	Student s3;
	s3 = s1;
	s3.Print();

	std::cout << "\n=== With inheritance, comparison may lead to unexpected results!\n";

	s3.SetFn(s2.GetFn() + 1);

	std::cout
		<< "FN1 is " << s2.GetFn()
		<< ", FN2 is " << s3.GetFn()
		<< ", are they equal: " << ((s3 == s2) ? "True" : "False") << "\n";

	std::cout << "\n=== Leaving main()\n";

    return 0;
}