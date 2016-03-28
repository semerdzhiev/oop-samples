/********************************************************************
*
* This file is part of the Data Structures in C++ Course Examples package.
*
* Author: Atanas Semerdzhiev
* URL: https://github.com/semerdzhiev/sdp-samples
*
*/

// 
// This program outputs the size of a file (in bytes) to STDOUT
//

#include <iostream>

#include <fstream>

int main(int argc, char* argv[])
{
	std::ifstream in;

	// Check whether the file path has been passed
	if(argc != 2)
	{
		// If the path was not passed as an argument,
        // we give the user an option to enter it now

		// This buffer will store the file path
		char buffer[_MAX_PATH];

		std::cout << "Path: ";
		std::cin.getline(buffer, _MAX_PATH);

		in.open(buffer);
	}
	else
	{
		// The path has been passed as an argument
		in.open(argv[1]);
	}

	// Check whether the file has been opened successfully
	if( ! in)
	{
		std::cerr << "Cannot open the file for reading!\n";
		return 1;
	}

	// We obtain the file size by seeking to its end and
    // then checking the current position
	in.seekg(0, std::ios::end);

	size_t size = in.tellg();

	// We no longer need the file, so we can close it
	in.close();

	// Display the size
	std::cout << "Size: " << size << " bytes\n";

	return 0;
}
