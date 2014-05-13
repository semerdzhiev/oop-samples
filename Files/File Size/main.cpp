// 
// Програмата извежда на екрана размера на даден файл
//

#include <iostream>

#include <fstream>

int main(int argc, char* argv[])
{
	std::ifstream in;

	// Проверяваме дали пътят до файла е подаден от командния ред
	if(argc != 2)
	{
		// Ако пътят не е подаден от командния ред,
		// даваме възможност на потребителя да го въведе

		// Създаваме буфер, в който да съхраним името на файла
		// _MAX_PATH е вградена константа
		char buffer[_MAX_PATH];

		std::cout << "Path: ";
		std::cin.getline(buffer, _MAX_PATH);

		in.open(buffer);
	}
	else
	{
		// Пътят към файла е подаден от командния ред
		in.open(argv[1]);
	}

	// Проверяваме дали файлът е бил отворен успешно
	if( ! in)
	{
		// Ако това не е така, извеждаме съобщение за грешка
		std::cerr << "Cannot open the file for reading!\n";
		return 1;
	}

	// Взимаме размера на файла като отидем в неговия край
	// и проверим текущата позиция
	in.seekg(0, std::ios::end);

	size_t size = in.tellg();

	// Затваряме файла, защото повече няма да го използваме
	in.close();

	// Извеждаме размера на файла
	std::cout << "Size: " << size << " bytes\n";

	return 0;
}
