#include <cstring>
#include <iostream>

#include "Student.h"


///
/// Default constructor: Initializes an empty Student object
///
Student::Student()
{
	std::cout << "[0x" << this << "] Student::Student()\n";

    m_Fn = 0;
}


///
/// Initializes a new Student object with specific values 
///
Student::Student(unsigned int Fn, const char* Name, const char* Phone) : Person(Name, Phone)
{
	std::cout << "[0x" << this << "] Student::Student("
        << Fn << ", "
        << Name << ", "
        << Phone << ")\n";

    SetFn(Fn);
}


///
/// Frees the resources used by a Student object
///
Student::~Student()
{
	std::cout << "[0x" << this << "] Student::~Student()\n";
}

///
/// Copy constructor
///
Student::Student(Student const & other)
{
	std::cout << "[0x" << this << "] Student::Student([0x" << &other << "])\n";

    CopyFrom(other);
}


///
/// Assignment operator
///
//Student& Student::operator=(Student const& other)
//{
//	std::cout << "[0x" << this << "] Student::operator=([0x" << &other << "])\n";
//
//    if (this != &other)
//    {
//        CopyFrom(other);
//    }
//
//    return *this;
//}


///
/// Copies the data from another Student object to this one.
///
/// The function assumes that both objects have been
/// correctly initalized and in correct state.
///
void Student::CopyFrom(Student const & other)
{
    SetFn(other.GetFn());
	Person::CopyFrom(other);
}


///
/// Returns the faculty number of the student
///
unsigned int Student::GetFn() const
{
    return m_Fn;
}


///
/// Modifies the faculty number of the student
///
/// The function performs a simple check on the
/// faculty number. If it is found to be incorrect,
/// the object's data will not be modified.
///
void Student::SetFn(unsigned int value)
{
    if (value <= 89999)
        m_Fn = value;
}


///
/// Display information about the student
/// object to STDOUT
///
void Student::Print() const
{
    std::cout
        << "A student object at 0x" << this
        << "\n  FN\t" << GetFn()
        << "\n";

	Person::Print();
}

void Student::PrintSizeInfo()
{
    std::cout
        << "The size of a Student object is "
        << sizeof(Student)
        << "\n";

	std::cout
		<< "\nOffset between Student and Fn is "
		<< offsetof(Student, m_Fn)
		<< "\n";

	Person::PrintSizeInfo();
}
