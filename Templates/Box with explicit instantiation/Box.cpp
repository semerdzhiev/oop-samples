#include <string>

#include "Box.h"

///
/// Създава празна кутия
///
template <typename TYPE>
Box<TYPE>::Box()
{
	Stuff = 0;
}


///
/// Създава кутия съдържаща елемент Value
///
template <typename TYPE>
Box<TYPE>::Box(TYPE Value)
{
	Stuff = Value;
}


///
/// Връща съдържанието на кутията
///
template <typename TYPE>
TYPE Box<TYPE>::Peek() const
{
	return Stuff;
}


///
/// Променя съдържанието на кутията
///
template <typename TYPE>
void Box<TYPE>::Store(const TYPE Value)
{
	Stuff = Value;
}


//-------------------------------------------------------------

///
/// Създава празна кутия
///
Box<char*>::Box()
{
	Stuff = NULL;
	Length = 0;
}


///
/// Създава кутия съдържаща символния низ pText
///
/// \param pText
///    Символният низ, който ще бъде съхранен в кутията.
///    Ако pText е NULL, ще се създаде празна кутия.
///
Box<char*>::Box(char *pText)
{
	Stuff = NULL;
	Length = 0;
	Store(pText);
}


///
/// Освобождава паметта заета от кутията
///
Box<char *>::~Box()
{
	delete[] Stuff;
}



///
/// Връща символния низ съхранен в кутията
///
char* Box<char*>::Peek() const
{
	return Stuff;
}


///
/// Записва символния низ pText в кутията
///
/// \param pText
///    Символният низ, който ще бъде копиран в кутията.
///    Ако pText е NULL, кутията става празна и заетата
///    от нея памет се освобождава.
///
void Box<char*>::Store(char* pText)
{
	char* pNewString = NULL;
	size_t newLength = 0;

	if (pText)
	{
		newLength = strlen(pText);

		char *pNewString = new char[newLength + 1];

		strcpy_s(pNewString, newLength + 1, pText);
	}

	delete[] Stuff;
	Stuff = pNewString;
	Length = newLength;
}


///
/// Връща дължината на символния низ съхранен в кутията
///
size_t Box<char*>::GetStringLength() const
{
	return Length;
}


template class Box <int> ;
template class Box < double > ;
