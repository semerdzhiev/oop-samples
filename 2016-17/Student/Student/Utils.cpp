#include <string.h>
#include <iostream>

///
/// Allocates memory for a new zero-terminared string and
/// copies a value into it
///
void AllocateAndCopy(char*& ptr, const char* value)
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
        // TODO: When later in the course we cover exceptions,
        //       change the way this error is handled.
        std::cerr << "Not enough memory!\n";
    }
}