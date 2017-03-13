#include <iostream>

#include "StudentCollection.h"

void TestStudentClass()
{
    std::cout << "\n== Enter TestStudentClass()\n";

    std::cout << "\n== Create a single object\n";
    Student s;
    s.Print();

    s.SetName("Ivan");
    s.Print();

    s.SetFn(12345);
    s.SetName("Ivan Ivanov");
    s.SetPhone("+359887123456");
    s.Print();

    // Create and copy objects
    std::cout << "\n== Create another object and copy from the first one (copy constructor)\n";
    Student t = s;

    std::cout << "\n== Create another object and copy from the first one (copy constructor)\n";
    Student q;
    q = s;

    // Create and free an array of objects
    std::cout << "\n== Create and free an array of objects\n";
    Student *parr = new Student[5];
    delete[] parr;

    // Create and free a single object
    std::cout << "\n== Create and free a single object\n";
    Student *p = new Student(12345, "Ivan Ivanov", "1234567890");
    delete p;

    std::cout << "\n== Leave TestStudentClass()\n";
}

int main()
{
    TestStudentClass();

    return 0;
}