// texample.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <iomanip>

using namespace std;

//
// template is with keyword
// 'class' or 'typename'
//

template <typename T>
class PrintFormatter {
private:
	T var;

public:
	void print() {
		cout << setw(10) << var << endl;
	}

	PrintFormatter() {
		cout << "create object with variable size " << sizeof(T) << endl;
	}

	PrintFormatter(T _var) { 
		cout << "setting new value for template var " << _var << endl;
		var = _var;
	}

	// setter & getter 

	T getvar(T nval) { 
		if (nval) { 
			var = nval;
		}

		return var;
	}
};


class Point { 
	float x, y;
public:
	Point() : x(0), y(0) { /*... */ }
	Point(float _x, float _y) : x(_x), y(_y) { /*...*/ };
	
	friend ostream& operator << (ostream& ostr, Point& p);
};


ostream& operator << (ostream& ostr, Point& p) { 
	ostr <<  '(' <<
		p.x << ',' << 
		p.y << ')';

	return ostr;
}


int main() {
	PrintFormatter <int> ivar;
	PrintFormatter <char> cvar;
	PrintFormatter <Point> mvar;

	// these 'magically' work as 
	// we have a constructor with
	// the template class which
	// acts as assignment operator

	ivar = 10;
	cvar = 'a';
	mvar = Point(1, 5);

	ivar.print();
	cvar.print();
	mvar.print();

	return 0;
}


