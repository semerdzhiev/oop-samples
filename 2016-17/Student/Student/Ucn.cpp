#include <cstdlib>

#include "Ucn.h"

const int Ucn::UcnSize = 10;

///
/// Checks whether a given date is valid and can be stored in a UCN
///
/// UCNs can store dates between 01.01.1800 and 31.12.2099
///
/// The function checks whether the specified date is valid
/// (e.g. 31.02.2004 is not a valid date) and whether it
/// falls in the given range (01.01.2100 is a valid date,
/// but currently there are no rules for storing it in a UCN).
///
bool Ucn::IsValidUcnDate(int Day, int Month, int Year)
{

    //
    // If one of these is true:
    //   - the year is outside of the range of valid years for UCN numbers OR
    //   - the month value is incorrect OR
    //   - the day value is less than 1
    // then this is not a valid UCN date
    //
    if (Year < 1800 || Year > 2099 || Month < 1 || Month > 12 || Day < 1)
        return false;

    // April, June, September and November have 30 days
    if (Month == 4 || Month == 6 || Month == 9 || Month == 11)
        return Day <= 30;
    
    // Febrauary is special
    else if (Month == 2)
    {
        // On a leap year February has 29 days, otherwise - 28
        if (Year % 400 == 0 || (Year % 4 == 0 && Year % 100 != 0))
            return Day <= 29;
        else
            return Day <= 28;
    }

    // All other months have 30 days
    else
        return Day <= 30;
}


///
/// Retrieve the month information component of a UCN
///
/// Month information is stored in the third and fourth
/// digits of the UCN.
/// The value may be greater than 12, because for
/// people born before 1900, 20 is added to the
/// month and for people born after 1999, 40 is added.
/// Thus in order to use the information, one needs to 
/// restore the original value, by applying mod 20.
///
inline int Ucn::GetUcnMonthRaw(unsigned long long Ucn)
{
    return (Ucn / 1000000) % 100;
}


///
/// Retrieve the year component of a UCN
///
/// The year of birth is stored in the first and second
/// digits of the UCN.
/// This value depends on the value for the month.
/// For people born before 1900, 20 is added to the
/// month and for people born after 1999, 40 is added.
///
inline int Ucn::GetUcnYearRaw(unsigned long long Ucn)
{
    return (int)(Ucn / 100000000);
}


///
/// Construct an empty UCN object
///
Ucn::Ucn()
{
    Value = 0;
}


///
/// Construct a UCN object and assign a value to it
///
Ucn::Ucn(unsigned long long Value)
{
    FromNumber(Value);
}


///
/// Construct a UCN object and assign a value to it
///
Ucn::Ucn(const char * Value)
{
    FromString(Value);
}


///
/// Sets the value of the UCN object
///
void Ucn::FromNumber(unsigned long long Value)
{
    this->Value = Value;
}


///
/// Sets the value of the UCN object
///
void Ucn::FromString(const char * Value)
{
    FromNumber(strtoull(Value, NULL, 10));
}


///
/// Returns the UCN as an integer
///
unsigned long long Ucn::ToNumber() const
{
    return Value;
}


///
/// Returns the UCN as a string
///
const char * Ucn::ToString() const
{
    static char buffer[11] = { 0, };

    // If the number has more than 10 digits (not a valid UCN)
    // it will not fit in the buffer
    if (Value < 10000000000)
    {
        unsigned long long Temp = Value;
        int i = UcnSize - 1;

        while (Temp > 0)
        {
            buffer[i] = Temp % 10;
            Temp /= 10;
            --i;
        }
    }

    return buffer;
}


///
/// Checks whether the date information of the currently stored UCN is valid.
///
bool Ucn::VerifyDate() const
{
    return GetUcnMonthRaw(Value) <= 52 &&
           IsValidUcnDate(GetDay(), GetMonth(), GetYear());
}


///
/// Verifies the currently stored UCN against its checksum digit
///
bool Ucn::VerifyChecksum() const
{
    int UcnDigitWeights[] = { 2, 4, 8, 5, 10, 9, 7, 3, 6 };

    int weightedSum = 0;
    unsigned long long temp = Value / 10;
    int i = UcnSize - 2;

    while (temp)
    {
        weightedSum += (temp % 10) * UcnDigitWeights[i];
        temp /= 10;
        --i;
    }

    int checksum = weightedSum % 11;

    if (checksum == 10)
        checksum = 0;

    return checksum == Value % 10;
}


///
/// Checks whether the currently stored value is a valid UCN
///
bool Ucn::IsValid() const
{
    return VerifyDate() && VerifyChecksum();
}


///
/// Checks whether the UCN belongs to a male
///
/// The ninth digit in the UCN is even for
/// males and odd for females.
///
bool Ucn::IsMale() const
{
    return ((Value / 10) % 10) % 2 == 0;
}


///
/// Checks whether the UCN belongs to a male.
///
/// The ninth digit in the UCN is even for
/// males and odd for females.
///
bool Ucn::IsFemale() const
{
    return ! IsMale();
}


///
/// Returns the year of birth of the person with
/// the currently stored UCN number.
///
/// \warning
///     This value will only be correct if a valid UCN
///     has been stored in the object.
///     Call the IsValid() function to verify the UCN.
///
int Ucn::GetYear() const
{
    int MonthRawValue = GetUcnMonthRaw(Value);
        
    int Year = 1900 + GetUcnYearRaw(Value);

    if (MonthRawValue >= 40)
        Year += 100;
    else if (MonthRawValue >= 20)
        Year -= 100;

    return Year;
}


///
/// Returns the month of birth stored in the UCN
///
/// \warning
///     This value will only be correct if a valid UCN
///     has been stored in the object.
///     Call the IsValid() function to verify the UCN.
///
int Ucn::GetMonth() const
{
    return GetUcnMonthRaw(Value) % 20;
}


///
/// Returns the day of birth stored in the UCN
///
/// \warning
///     This value will only be correct if a valid UCN
///     has been stored in the object.
///     Call the IsValid() function to verify the UCN.
///
int Ucn::GetDay() const
{
    return (Value / 10000) % 100;
}
