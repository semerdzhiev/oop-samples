// homework.help.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

const int CGROW = 10; 

typedef unsigned int uint;

// реализация, която ще работи за всички видове указатели
// в рамките на една система
uint grow(void **wh, uint ccount, uint ngrow = CGROW) {
	// заделяне на временна памет
	void *temp = new void*[ccount];

	if (ccount)  {
		// взимаме съществуващите указатели 
		// и ги запазваме някъде
		memcpy(temp, *wh, sizeof(void*) * ccount );
	}

	if ( *wh ) { 
		// освобождаване на заделената преди памет
		delete *wh;
	}

	// заделяне на нова памет с новия размер
	*wh = new void*[ccount + ngrow];

	// ако не сме успели да заделим памет
	if ( *wh == NULL ) return 0;

	// преместване на указателите в новото място
	memcpy(*wh, temp, sizeof(void*) * ccount );

	// изтриване на временната памет
	delete temp;

	return ngrow + ccount;
}

// шаблон за реализация, която ще работи за всички типове
// познати на компилатора
template <class T>
uint growt(T *&wh, uint  ccount, uint ngrow =  CGROW) {
	// заделяне на временна памет
	void *temp = new T[ccount];

	if (ccount)  {
		// взимаме съществуващите указатели 
		// и ги запазваме някъде
		memcpy(temp, wh, sizeof(T) * ccount );
	}

	if ( wh ) { 
		// освобождаване на заделената преди памет
		delete wh;
	}

	// заделяне на нова памет с новия размер
	wh = new T[ncount+ngrow];

	// ако не сме успели да заделим памет
	if ( wh == NULL ) return 0;

	// преместване на указателите в новото място
	memcpy(wh, temp, sizeof(T) * ccount);

	// изтриване на временната памет
	delete temp;

	return ncount+ngrow;
}

int *tarr;
char ** strings;

int main(int argc, char* argv[]) {
	grow((void**))&strings, 0);
	uint csize = growt<int>(tarr, 0);
	
	growt<char*>(strings, 0);

	for (int i=0; i<100; i++) {
		if ( i >= csize ) { 
			csize = growt<int>(tarr, csize);
		}
		tarr[i] = i;
	}

	return 0;
}
