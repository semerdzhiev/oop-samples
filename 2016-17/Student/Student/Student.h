#pragma once

#include "Person.h"

///
/// Represents a student from Sofia University
///
/// The class
///
class Student : public Person {
private:

    ///
    /// The faculty number of the student
    ///
    /// This is an uniqie identifier used internally in SU
    ///
    unsigned int m_Fn;

private:
    void CopyFrom(Student const& other);

public:
    Student();
    Student(unsigned int Fn, const char* Name, const char* Phone);
    Student(Student const& other);
    ~Student();

    unsigned int GetFn() const;
    void SetFn(unsigned int value);

    void Print() const;
    static void PrintSizeInfo();
};