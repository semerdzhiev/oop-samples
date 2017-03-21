#include <cstring>
#include <iostream>

#include "Student.h"


///
/// Allocates a new string and copies the contents of value
///
void Student::SetNewValue(char *& ptr, const char * value)
{
    // If NULL has been passed, free the memory instead
    if (!value)
    {
        delete[] ptr;
        ptr = NULL;
        return;
    }

    // If a valid string has been passed, make a copy
    try {
        size_t BufferSize = strlen(value) + 1;

        char* buffer = new char[BufferSize];
        delete[] ptr;
        ptr = buffer;

        strcpy_s(ptr, BufferSize, value);
    }
    catch (std::bad_alloc&)
    {
        std::cerr << "Not enough memory!\n";
    }
}


///
/// Default constructor: Initializes an empty Student object
///
Student::Student()
{
    std::cout
        << "[0x"
        << this
        << "] Entering Student::Student()\n";

    Fn = 0;
    Name = NULL;
    Phone = NULL;
}


///
/// Initializes a new Student object with specific values 
///
Student::Student(unsigned int Fn, const char* Name, const char* Phone)
{
    std::cout
        << "[0x"
        << this
        << "] Entering Student::Student("
        << Fn << ", "
        << Name << ", "
        << Phone << "\n";

    this->Fn = 0;
    this->Name = NULL;
    this->Phone = NULL;

    SetFn(Fn);
    SetName(Name);
    SetPhone(Phone);
}


///
/// Frees the resources used by a Student object
///
Student::~Student()
{
    std::cout
        << "[0x"
        << this
        << "] Entering Student::~Student()\n";

    delete[] Name;
    delete[] Phone;
}

///
/// Copy constructor
///
Student::Student(Student const & other)
{
    std::cout
        << "[0x"
        << this
        << "] Entering Student::Student([0x"
        << &other
        << "])\n";

    Fn = 0;
    Name = NULL;
    Phone = NULL;

    CopyFrom(other);
}


///
/// Assignment operator
///
Student& Student::operator=(Student const& other)
{
    std::cout
        << "[0x"
        << this
        << "] Entering Student::operator=([0x"
        << &other
        << "])\n";


    if (this != &other)
    {
        CopyFrom(other);
    }

    return *this;
}


///
/// Copies the data from another Student object to this one.
///
/// The function assumes that both objects have been
/// correctly initalized and in correct state.
///
void Student::CopyFrom(Student const & other)
{
    SetFn(other.GetFn());
    SetName(other.GetName());
    SetPhone(other.GetPhone());
}


///
/// Returns the faculty number of the student
///
unsigned int Student::GetFn() const
{
    return Fn;
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
    if (Fn <= 89999)
        Fn = value;
}


///
/// Returns the name of the student
///
/// The function always returns a valid null-terminated
/// C++ string (i.e. it never returns NULL).
/// If no name has been specified for the student,
/// the function returns the empty string.
///
const char * Student::GetName() const
{
    return Name ? Name : "";
}


///
/// Modifies the name of the student
///
void Student::SetName(const char * value)
{
    SetNewValue(Name, value);
}


///
/// Returns the phone of the student
///
/// The function always returns a valid null-terminated
/// C++ string (i.e. it never returns NULL).
/// If no name has been specified for the student,
/// the function returns the empty string.
///
const char * Student::GetPhone() const
{
    return Phone ? Phone : "";
}


///
/// Modifies the phone of the student
///
void Student::SetPhone(const char * value)
{
    SetNewValue(Phone, value);
}


///
/// Display information about the student
/// object to STDOUT
///
void Student::Print() const
{
    std::cout
        << "A student object at 0x" << this
        << "\nFN: "     << GetFn()
        << "\nName: "   << GetName()
        << "\nPhone: "  << GetPhone()
        << "\n\n";
}

void Student::PrintSizeInfo()
{
    std::cout
        << "The size of a Student object is "
        << sizeof(Student)
        << "\n";

    std::cout
        << "\nOffset between Student and Fn is "
        << offsetof(Student, Fn)
        << "\nOffset between Student and Name is "
        << offsetof(Student, Name)
        << "\nOffset between Student and Phone is "
        << offsetof(Student, Phone)
        << "\n";
}
