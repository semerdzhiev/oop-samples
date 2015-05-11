// simplevector.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <vector>
#include <iostream>
#include <sstream>

using namespace std;

void stream_read()  {
	vector<int> myvec;
	char c;
	int cnum = -1;

	do {
		c = cin.get();
		if ( c == ' ' ) {
			if (cnum >= 0) 
				myvec.push_back(cnum);
			cnum = -1;
		} else {
			if ( cnum < 0 ) cnum = 0;
			cnum = cnum * 10 + c - '0';
		}
	} while (c != '\n');

}

void until_stream_closed() { 
	vector<int> myvec;

	while ( ! cin.eof() ) {
		int cnum;
		cin >> cnum;
		myvec.push_back(cnum);
	}
}

int limited_line_strstream() { 
	vector<int> myvec;
	char buf[1024];
	cin.getline(buf, 1024);

	istringstream istr(buf);
	
	while ( ! istr.eof() ) {
		int cnum;
		istr >> cnum;
		myvec.push_back(cnum);
	}
}

void stlonly() {
	vector<int> myvec;
	string line;
	getline(cin, line);
	istringstream iss(line);
	int num;
	while ( iss >> num) {    
		myvec.push_back(num);
	}
}
