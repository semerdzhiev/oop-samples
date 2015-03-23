// file-io.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <fstream>

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


	void print() {
		cout << intnum << " is located in " << dislocation << " and has weight " << weight;

	}

	void write(ofstream &ofs) {
		ofs << intnum << endl << dislocation << endl << weight;
	}

	void write_binary(ofstream &ofs) {
		unsigned int msize = strlen(intnum);

		ofs.write((const char *) &msize, 4);
		ofs.write(intnum, msize);

		msize = strlen(dislocation);

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

 // constructor
Inventory::Inventory() : weight(0) {
	cout << "Object created. Address is " << hex << this;
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

int main() {
	// allocate memory
	Inventory* inv[7];

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
	ifstream ifs("c:\\temp\\INPUT.txt");

	if  (! ifs.is_open()) {
		cout << "error opening file";	
		return 255;
	}

	ifs >> icount;

	for (auto i=0; i<icount && i<(sizeof(inv) / sizeof(Inventory*)); i++) {
		inv[i] = new Inventory;
		ifs >> inv[i];
	}

//	fclose(fh);
	return 0;
}


