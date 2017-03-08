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
/// Initializes an empty Student object
///
Student::Student()
{
    Fn = 0;
    Name = NULL;
    Phone = NULL;
}


///
/// Frees the resources used by a Student object
///
Student::~Student()
{
    delete[] Name;
    delete[] Phone;
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