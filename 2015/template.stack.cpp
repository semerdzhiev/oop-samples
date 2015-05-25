// stackimpl.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

template <typename T> 
class Stack { 
	
	/* the inner class is the actual stack element container */
	struct StElem {
		T* pl;
		StElem* next;
		StElem() : pl(NULL), next(NULL) { /* ... */ };
		StElem(const T&pl); 
		StElem(const T&_pl, StElem * _next);
		~StElem() {	delete this->pl; }
	};

	/* outer class methods operate on the stack elems */

public:
	Stack();
	unsigned int size();
	unsigned int push(const T&);
	T& top(); 
	unsigned int pop();

	Stack<T>& operator << (const T&);
	Stack<T>& operator >> ( T&);

private:
	StElem* _top;
	unsigned int _size;
};

/* the inner class constructors */

template<typename T>
Stack<T>::StElem::StElem(const T& _pl) : next(NULL) {
	this->pl = new T;
	*this->pl = _pl;
}

template<typename T>
Stack<T>::StElem::StElem(const T&_pl, StElem * _next) {
	this->pl = new T;
	*this->pl = _pl;			// pointer here, because we want to set the value !
	this->next = _next;
}

/* constructors of outer class */

template <typename T> 
Stack<T>::Stack() {
	_top = NULL;
	_size = 0;
}

template <typename T> 
unsigned int Stack<T>::size() {
	return _size;
}

/* basic stack operations */

template <typename T> 
unsigned int Stack<T>::push(const T&val) {
	if( _top ) {
		_top = new StElem(val, _top);
	} else {
		_top = new StElem(val);
	}

	return _size++;
}

template <typename T> 
T& Stack<T>::top() {
	return *_top->pl;
}

template <typename T> 
unsigned int Stack<T>::pop() {
	if (_size) {
		StElem* tmp = _top;
		_top = _top->next;
		delete tmp;

		return _size--;
	}

	return 0;
}

/* operators that simply call push/pop */

template<typename T>
Stack<T>& Stack<T>::operator << ( const T& val) {
	this->push(val);
	return *this;
}

template<typename T>
Stack<T>& Stack<T>::operator >> (T& val) {
	val = this->top();
	this->pop();

	return *this;
}

/* main */
int main() {
	int a, b = 20;
	Stack<int> st;

	st << 10 << b << 30 << 40 << 100;
	st >> a;

	cout << a;
	return 0;
}


