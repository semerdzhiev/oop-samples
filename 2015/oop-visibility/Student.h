#pragma once

/* за да може да наследим класа Person... трябва да знаем за неговото съществуване */

#include "Person.h"

class Student :
	public Person
{
	
	/* сега тук всички public променливи от 'родителския' клас са наследени като public,
	а всички private си остават 'private'. променливи с видимост 'proteceted' са достъпни
	само в родителския клас */


private: 

	int grade;
	char* _specialty;

	/* този init() не е онзи init()... .от Person. това е друг метод, който припокрива 
	родителския. казва се overrides на роден английски език */

	void init();
	void destroy();

public:
	Student(char *name, char* family, char* specialty);

	Student(void);
	~Student(void);

	char* specialty(char* );

	/* пример за видимост */
	void someMethod() { 
		this->_age = 10;

		/* подобна конструкция няма да е възможна, защото _name е private, 
		което прави достъпа до нея възможен само в съответния клас, който я
		декларира

			strcpy(this->_name, "Test");

		*/
	}
};

