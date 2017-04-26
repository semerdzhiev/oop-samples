#pragma once

#include "Ucn.h"

///
/// Represents a Person
///
class Person {
private:

    ///
    /// Name of the person
    ///
    /// A string, which contains all names of the person
    /// (e.g. first and second name, joined by an interval)
    ///
    char *m_pName;

    ///
    /// Phone number of the person
    ///
    /// A phone number, which can be used to contact
    /// the person on administrative issues
    ///
    char *m_pPhone;

	///
	/// UCN of the person
	Ucn m_Ucn;

protected:
    void CopyFrom(const Person& other);

public:
    Person();
    Person(const char* Name, const char* Phone);
    Person(const Person& other);
    ~Person();

    Person& operator=(const Person& other);
	bool operator==(const Person& other) const;

    const char* GetName() const;
    void SetName(const char* value);

    const char* GetPhone() const;
    void SetPhone(const char* value);

    void Print() const;
    static void PrintSizeInfo();
};
