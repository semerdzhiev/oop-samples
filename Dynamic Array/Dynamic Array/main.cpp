#include <iostream>

#include "DynamicArray.h"

std::ostream& operator << (std::ostream& out, DynamicArray<int>& arr)
{
    if (! arr.IsEmpty())
    {
        out << arr.At(0);

        for (size_t i = 1; i < arr.GetSize(); ++i)
            out << ", " << arr.At(i);
    }
    else
    {
        out << "(empty)";
    }

    return out;
}

int main()
{
    DynamicArray<int> arr;

    std::cout << "Newly created array:\n\t" << arr << std::endl;

    for(int i = 0; i <= 5; ++i)
        arr.Append(i);

    std::cout << "\nArray filled with integers:\n\t" << arr << std::endl;

    arr = arr + 100;

    std::cout << "\nArray after appending 100:\n\t" << arr << std::endl;

    arr = -1 + arr;

    std::cout << "\nArray after prepending -1:\n\t" << arr << std::endl;

    DynamicArray<int> newArr = arr + arr;

    std::cout << "\nNew array:\n\t" << newArr << std::endl;
}