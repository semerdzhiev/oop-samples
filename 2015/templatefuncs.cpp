// templateintro.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <math.h>
#include <list>

using namespace std;

// with typename, not class 
// find the max element in 
// array of some type.
// PLEASE NOTE -> typename, not class

template <typename T> 
T max(T* elems, int nelems) {
	int cmax = 0;

	for (int i=1; i<nelems; i++) { 
		if (elems[i] > elems[cmax])  {
			cmax = i;
		}
	}

	return elems[cmax];
};

// with list of some elements
// template param. please note -> class
// may be a list of your own objects
// and also...
// we can either write class or typename

template <class Y>
Y max(list<Y> &elems) {
	Y cmax = elems.front();

	// ... but 
	// we need typename before the list<Y>::iterator
	// because the compiler does not yet what type is
	// this and we need to tell it  it is a type

	for (typename list<Y>::iterator it = elems.begin(); it != elems.end(); ++it) {
   		if (*it > cmax)  {
			cmax = *it;
		}
	}

	return cmax;
};

// some class to help us with the demo
// a sample ortho class vector


class Vector { 
	float x, y; 

public:
	// returns the length of the vector
	float len() {
		return sqrt(x*x + y*y);
	}

	Vector(float _x, float _y) : x(_x), y(_y) {
	
	};

	bool operator > (Vector &v2) {
		return this->len() > v2.len();
	}
};


int main() {
	int a[] = { 1, 2, 4, -1, -10};
	Vector v[] = { Vector( 10, 10 ) , Vector(5.32, 10.23),  Vector (-10, -20) };
	
	// find the largest value
	int imax = max<int>(a, sizeof(a) / sizeof(a[0])); 

	// find the logest vector
	Vector vmax = max<Vector>(v, sizeof(v) / sizeof(v[0])); 

	// with template instance

	// add some items to the dynamic list
	list<int> l;
	l.push_back(1);
	l.push_back(-5);
	l.push_back(-3);

	// find the largest value
	int x = max<int>(l);

	return 0;
}


