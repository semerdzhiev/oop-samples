// file-io.cpp : Defines the entry point for the console application.
//

// note -> use g++ file-io.cpp -std=c++11
// to compile with GNU C

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

char buf[1024];

struct Inventory {
	char* intnum;
	char* dislocation;
	float weight;

	// constructor. this pointer is implicit parameter
	Inventory();
	Inventory(Inventory *inv); 
	~Inventory();

	void read(ifstream& ifs) {
		ifs >> intnum >> dislocation >> weight;
	}

	void print(ostream& ostr) {
		if (dislocation && weight) { 
			ostr << intnum 
				<< " is located in " << dislocation 
				<< " and has weight " << weight
				<< endl;
		}
	}

	void write(ofstream &ofs) {
		ofs << intnum << endl << dislocation << endl << weight;
	}

	void write_binary(ofstream &ofs) {
		unsigned int msize = strlen(intnum) + 1;
		ofs.write((const char *) &msize, 4);
		ofs.write(intnum, msize);

		msize = strlen(dislocation) + 1;
		ofs.write((const char *) &msize, 4);
		ofs.write(dislocation, msize);

		ofs.write((const char *) &weight, sizeof(float));
	}
};

// operator overload
// OPERAND operator OPERAND 
ifstream& operator >> (ifstream &ifs, Inventory* inv) {
	inv->read(ifs);
	return ifs;
}

ostream& operator << (ostream &ostr, Inventory* inv) {
	inv->print(ostr);
	return ostr;
}

 // constructor
Inventory::Inventory() 
	: weight(0), dislocation(NULL), intnum(NULL) {
	cout << "Inventory object created. Address is " << hex << (void*) this << endl;
	dislocation = new char[128];
	intnum = new char[128];
}

// copy constructor
Inventory::Inventory(Inventory *inv) {
	cout << "Object created. Address is 		" << hex << this;

	this->dislocation = new char[strlen(inv->dislocation)];
	this->intnum = new char[strlen(inv->intnum)];

	this->weight = inv->weight;

	memcpy(this->dislocation, inv->dislocation, strlen(inv->dislocation));
	memcpy(this->intnum, inv->intnum, strlen(inv->dislocation));
}

// destructor
Inventory::~Inventory() {
	delete dislocation;
	delete intnum;
}

/* not a method
// constructor (C style fashion)
void initInventory(Inventory *self) { 
	self->dislocation = (char*) malloc(128);
	self->intnum= (char*) malloc(128);
	self->width = self->height = self->weight = 0;
}
*/

void removeInventory(Inventory *self) {
	delete self->dislocation;

	// free(self->dislocation) ...

}

inline void be2le(unsigned int& v) {
	// no braces here, because
	// << and >> are higher than & and it is higher than |
	v =  v << 24 |
	v >> 8 & 0x0000FF00 |
	v << 8 & 0x00FF0000 |
	v >> 24;
	
	// alternate :
	/* 

	( v << 24 ) + ((v & 0x00FF0000) >> 8) + ((v & 0x0000FF00) << 8) + (v >> 24)

	or 

	v << 24 | (v & 0x00FF0000) >> 8 | (v & 0x0000FF00) << 8 | v >> 24

	*/
}

int main() {
	// allocate memory
	Inventory* inv[7];
	memset(inv, 0, sizeof(inv));

	unsigned int icount;

//	C-style 
/*	FILE* fh = new FILE;
	if ( fopen_s(&fh, "c:\\temp\\INPUT.txt", "r") ) {
		cout << "error opening file";
		return;
	}

	fscanf_s(fh, "%u", &icount, sizeof(icount));
	fgets(buf, 1024, fh);		// read all until the end */

// C++ Style
// input files tream - ifstream
	ifstream ifs("c:\\temp\\INPUT.txt");

// output file stream - ofstream
	ofstream ofs("c:\\temp\\INPUT.bin");

	if  (! ifs.is_open()) {
		cout << "error opening file";	
		return 255;
	}

	ifs >> icount;

	for (auto i=0; i<icount && i<(sizeof(inv) / sizeof(Inventory*)); i++) {
		inv[i] = new Inventory;
		ifs >> inv[i];
		cout << inv[i];
	}

	int le = 'A';

	cout << ifs.tellg() << " bytes read";

	ofs.write((char*) &icount, sizeof(icount));

	// an example of range based 
	for ( Inventory* ielem : inv ) {
		// if not NULL pointer
		if (ielem) {
			ielem->write_binary(ofs);
		}
	}

//	fclose(fh);
	return 0;
}

/*

	XX XX XX XX - 4 bytes integer for number of inventories

	X packages of bytes in the following order :

	{
		NN NN NN NN - 4 bytes - integer for size of character string
		AA .. AA	- N bytes - null terminated string 

		NN NN NN NN - 4 bytes - integer for size of character string
		AA .. AA	- N bytes - null terminated string 

		FF FF FF FF - 4 bytes for floating point variable

	}

*/

