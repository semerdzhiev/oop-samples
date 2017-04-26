#include <string.h>
#include <iostream>

#include "Utils.h"
#include "Person.h"

///
/// Default constructor: Initializes an empty Person object
///
Person::Person()
{
    std::cout << "[0x" << this << "] Person::Person()\n";

    m_pName = NULL;
    m_pPhone = NULL;
}


///
/// Initializes a new Person object with specific values 
///
Person::Person(const char* Name, const char* Phone)
{
    std::cout << "[0x" << this << "] Person::Person(" << Name << ", " << Phone << "\n";

    this->m_pName = NULL;
    this->m_pPhone = NULL;

    SetName(Name);
    SetPhone(Phone);
}


///
/// Frees the resources used by a Person object
///
Person::~Person()
{
    std::cout << "[0x" << this << "] Person::~Person()\n";

    delete[] m_pName;
    delete[] m_pPhone;
}


///
/// Copy constructor
///
Person::Person(const Person & other)
{
    std::cout << "[0x" << this << "] Person::Person([0x" << &other << "])\n";

    m_pName = NULL;
    m_pPhone = NULL;

    CopyFrom(other);
}


///
/// Assignment operator
///
Person& Person::operator=(const Person& other)
{
    std::cout << "[0x" << this << "] Person::operator=([0x" << &other << "])\n";

    if (this != &other)
        CopyFrom(other);

    return *this;
}


///
/// Checks whether two person objects contain the same information
///
bool Person::operator==(const Person & other) const
{
	std::cout << "[0x" << this << "] Person::operator==([0x" << &other << "])\n";

	return
		m_Ucn == other.m_Ucn &&
		strcmp(GetName(), other.GetName()) == 0 &&
		strcmp(GetPhone(), other.GetPhone()) == 0;
}


///
/// Copies the data from another Person object to this one.
///
/// The function assumes that both objects have been
/// correctly initalized and in correct state.
///
void Person::CopyFrom(const Person & other)
{
    SetName(other.GetName());
    SetPhone(other.GetPhone());
}


///
/// Returns the name of the person
///
/// The function always returns a valid null-terminated
/// C++ string (i.e. it never returns NULL).
/// If no name has been specified for the person,
/// the function returns the empty string.
///
const char * Person::GetName() const
{
    return m_pName ? m_pName : "";
}


///
/// Modifies the name of the person
///
void Person::SetName(const char * value)
{
    AllocateAndCopy(m_pName, value);
}


///
/// Returns the phone of the person
///
/// The function always returns a valid null-terminated
/// C++ string (i.e. it never returns NULL).
/// If no name has been specified for the person,
/// the function returns the empty string.
///
const char * Person::GetPhone() const
{
    return m_pPhone ? m_pPhone : "";
}


///
/// Modifies the phone of the person
///
void Person::SetPhone(const char * value)
{
    AllocateAndCopy(m_pPhone, value);
}


///
/// Display information about the person
/// object to STDOUT
///
void Person::Print() const
{
    std::cout
        << "A person object at 0x" << this
        << "\n  Name\t0x"  << (void*)m_pName  << " " << GetName()
        << "\n  Phone\t0x" << (void*)m_pPhone << " " << GetPhone()
        << "\n";
}

void Person::PrintSizeInfo()
{
    std::cout
        << "The size of a Person object is "
        << sizeof(Person)
        << "\n";

    std::cout
        << "\nOffset between Person and Name is "
        << offsetof(Person, m_pName)
        << "\nOffset between Person and Phone is "
        << offsetof(Person, m_pPhone)
        << "\n";
}
