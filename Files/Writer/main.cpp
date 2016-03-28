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
    unsigned int var = 0x12345678;

    unsigned short arr[3] = { 0xAB, 0xCD, 0xEF };

    const char str[] = "Hello world!";

    std::ofstream file;

    file.open("C:\\Temp\\test.dat");

    if ( ! file.is_open())
    {
        std::cerr << "Cannot open test.dat for writing!\n";
        return 1;
    }

    file.write((const char*)&var, sizeof(int));
    file.write((const char*) arr, sizeof(short) * 3);
    file.write(str, strlen(str) + 1);
    
    return 0;
}