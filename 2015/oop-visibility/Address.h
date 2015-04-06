#pragma once

class Address
{
private:
	char *_city;
	char *_address_line;
	int _zip;
	
	void init();
public:
	Address(void);
	~Address(void);
};

