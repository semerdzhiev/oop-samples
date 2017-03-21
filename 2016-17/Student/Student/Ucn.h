#pragma once

class Ucn
{
private:
    /// The number of digits in a UCN number
    static const int UcnSize;

    /// The UCN number
    unsigned long long Value;

public:
    static bool IsValidUcnDate(int Day, int Month, int Year);

public:
    static inline int GetUcnMonthRaw(unsigned long long Ucn);
    static inline int GetUcnYearRaw(unsigned long long Ucn);

public:
    Ucn();
    Ucn(unsigned long long Value);
    Ucn(const char* Value);

    void FromNumber(unsigned long long Value);
    void FromString(const char* value);

    unsigned long long ToNumber() const;
    const char* ToString() const;

    bool VerifyDate() const;
    bool VerifyChecksum() const;
    bool IsValid() const;
    bool IsMale() const;
    bool IsFemale() const;

    int GetYear() const;
    int GetMonth() const;
    int GetDay() const;
};