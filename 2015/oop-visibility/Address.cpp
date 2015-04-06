#include "stdafx.h"
#include "Address.h"

using namespace std;

void Address::init() {
	cerr << "init Address" << endl;

	_city = new char[MSIZE];
	_address_line = new char[MSIZE];
	_zip = 0;
}

Address::Address(void)
{
	init();
}


Address::~Address(void)
{
	/*...*/
}
