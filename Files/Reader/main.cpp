/********************************************************************
*
* This file is part of the Data Structures in C++ Course Examples package.
*
* Author: Atanas Semerdzhiev
* URL: https://github.com/semerdzhiev/sdp-samples
*
*/

#include <iostream>
#include <fstream>

int main()
{
    std::ifstream file;

    file.open("C:\\Temp\\test.dat");

    unsigned int var;
    unsigned short arr[3];

    file.read((char*)&var, sizeof(unsigned int));
    file.read((char*)arr, sizeof(unsigned short) * 3);

    // Display what has been read
    std::cout
        << "var: "
        << std::dec << var
        << " (0x" << std::hex << var << ")\n";

    for (int i = 0; i < 3; i++)
    { 
        std::cout
            << "arr[" << i << "]: "
            << std::dec << arr[i]
            << " (0x" << std::hex << arr[i] << ")\n";
    }

    return 0;
}