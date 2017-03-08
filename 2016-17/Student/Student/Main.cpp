#include <iostream>

#include "StudentCollection.h"

void TestStudentObject()
{
    Student s;
    s.Print();

    s.SetName("Ivan");
    s.Print();
    
    s.SetFn(12345);
    s.SetName("Ivan Ivanov");
    s.SetPhone("+359887123456");
    s.Print();
}

int main()
{
    TestStudentObject();

    return 0;
}