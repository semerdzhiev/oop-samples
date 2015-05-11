// warmup2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdio.h>

/*

 [ BASE ] (abstract)
    ^
	|
  [ A ]
    ^
	|
  [ B ]--->[ C ]
    ^        ^
    |        |
  [ E ]    [ D ]


 */

// abstract class
// the whoami() method has no implementation
// so instances of the BASE class are not
// directly possible
class Base {
	public:
		virtual void whoami() = 0;
};

class A : public Base {

public:
	A() {
		printf("construct A \n");
	}

	virtual void whoami() {
		printf ("i am A \n");
	}
};

class C {
	char c;
public:
	C() {
		printf("construct C \n");
	}

	virtual void whoami() {
		printf ("i am C \n");
	}
};

class B : public A {
	// the concstructor of C is going to be called
	// before the constructor of B
	C inst;
public:
	B() {
		printf("construct B \n");
	}

	virtual void whoami() {
		printf ("i am B \n");
	}

};

class D : public C {

public:
	D() {
		printf("construct D \n");
	}

	void whoami() {
		printf ("i am D \n");
	}
};

class E : public B {
	public:

	E() {
		printf("construct E \n");
	}

	virtual void whoami() {
		printf ("i am E \n");
	}
};

// using the Base class and virtual methods, we can implement
// a collection of objects descending from the same tree of inheritance
//

int main() {
	Base* instances[] =  {
		new B(),
		new E(),
		new A(),
	};

	printf("size of class E : %u \n", sizeof(E));

	for (int i = 0; i < sizeof(instances)/sizeof(A*); i++) {
		instances[i]->whoami();
	}

	return 0;
}


