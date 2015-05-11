// struct.welcome.cpp : Defines the entry point for the console application.
//
//
// Note : use g++ -std=c++11
// to compile with GCC

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <math.h>
#include <assert.h>

using namespace std;

struct Point {
	int x;
	int y;

	void read(ifstream& ifs) {
		ifs >> x >> y;
	}

	void print() {
		cout << "[" << this->x << "][" << this->y << "]";
	}
};

double dist(Point a, Point b) {
	return sqrt( (b.x - a.x)*(b.x - a.x) + (b.y - a.y)*(b.y - a.y) );
}

struct Polygon {
	Point *vs;
	unsigned int nv;
	double mylen;

	Polygon() : vs(NULL) {
		/* ... */
	}

	// constructor
	Polygon(int _nv) : mylen(0) {
		vs = new Point[_nv];
		nv = _nv;
	}

	// destructor
	~Polygon() {
		if (vs)
			delete vs;
	}

	// метод = member function
	void read(ifstream &ifs) {
		for(auto i=0; i < nv; i++ ) {
			vs[i].read(ifs);
		}
	}

	void print() {
		cout << "Polygon : ";

		for(auto i=0; i < nv; i++ ) {
			vs[i].print();
			if (i < nv-1) cout << ',';
		}

		cout << endl;
	}

	double length() {
		if (this->mylen )  {
			return this->mylen;
		} else {
			double len = 0;
			// C++11 specific
			for(auto i=0; i < nv - 1; i++ ) {
				len += dist(vs[i], vs[i+1]);
			}

			return (this->mylen = len);
		}
	}
};

int main() {
	ifstream ifs;
	ifs.open("INPUT.TXT");

	if (!ifs.is_open()) {
		cout << "error opening file";
		return 255;
	}

	int nv;			// брой на върхове в полигона

	ifs >> nv;
	assert(nv > 0);
	Polygon p(nv);
	p.read(ifs);
	p.print();

	cout << "Polygon length is : " << p.length() << endl;
	cout << "Polygon length is : " << p.length() << endl;

	return 0;
}

