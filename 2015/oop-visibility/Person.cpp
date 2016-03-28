#include "stdafx.h"
#include "Person.h"

/* в този файл са реализациите */

/*
	това е стандартен шаблон за създаване на setter/getter, чрез един метод.

	вместо да имаме getname() и setname(char*), обединяваме двете в едни метод, л
	който има стойност по подарзбиране за аргумента - NULL. и така ако напишем

	obj->name() 

	ше получим желаната скрита променлвиа, а ако напишем :
 
	obj->name(newvalue)

	ще зададем нова стойност

	*/


char* Person::name(const char *nname = NULL) {
	if (nname != NULL) { 
		/* тук може да се направи проверка... например за дължина на символния низ */
		int nlen = strlen(nname);
		assert(nlen < MSIZE);
		
		delete _name;
		_name = new char[strlen(nname) + 1];
		strcpy_s(_name, nlen+1, nname);
	}

	return _name;
}

/* писането на getters/setters е... досадно и понякога повтаря код. 

можем да помислим как да го "автоматизираме" или да изнесем общите части 
в някакви помощни функции.

някои автори се противопоставят на идеята за скрити променливи, а в някои
езици (python/perl/javascript) тя е пропусната и се използват трикове, за
да има реализация на такива.

определен стил на писане в Java и C# въвежда идеята за директна работа
с променливите с презумцията, че "който си пише кода си знае какво да направи
после с променливите". това в голям брой от случаите е практически вярно, но
при работа в екип се налагат допълнителни ограничения и за това няма 
да е изненада да срещнете класове с дълги getter/setter секции

*/

char* Person::family(const char *nfamily = NULL) {
	if (nfamily != NULL) { 
		/* тук може да се направи проверка... например за дължина на символния низ */
		int nlen = strlen(nfamily);
		assert(nlen < MSIZE);
		
		delete _family;
		_family = new char[strlen(nfamily) + 1];
		strcpy_s(_family, nlen+1, nfamily);
	}

	return _family;
}


void Person::print() {
	/* подобен ред не би извел синтактична грешка, но няма да прави това, кеото искаме 

	cout << name << ' ' << family;

	*/

	cout << _name << ' ' << _family;
}

void Person::print(ostream& ostr) {
	ostr << _name << ' ' << _family;
}

void Person::read(istream& istr) {
	istr >> _name >> _family;
}

/* ще си направя и един помощен оператор за извеждане...

понеже са дефинирани като приятелски, тези функции ще могат
да достъпват данните от класа директно, независимо дали 
става дума за данни, които са public или private

*/

ostream& operator << (ostream& ostr, Person &p) {
	ostr << p._name << ' ' << p._family;
	return ostr;
}

/* copy&paste е най-големият враг на програмиста... */

istream& operator >> (istream& istr, Person &p) {
	istr >> p._name >> p._family;
	return istr;
}

void Person::init() { 
	cerr << "init Person" << endl; 


	/* понеже имам и метод и данни с едно и също име тук трябва 
	да уточня кое от двете имам предвид. използвам this указател 
	експлицитно въпреки, че за член-данни той се подразбира */

	this->_name = new char[MSIZE];
	this->_family = new char[MSIZE];

	/* с това де факто казвам "_name и _family ще сочат към празен символен низ" */

	_name[0] = _family[0] = 0;
}

void Person::destroy() { 

	/* тук не напишем [] до името на променливите, 
	за които освобождаваме памет, защото това не са масиви от обкети
	и искаме директно да се освободи само паметта на адреса, който
	се сочи от съотв. променлива. на практика няма да има разлика
	в генерирания код */

	delete this->_name;
	delete this->_family;
}

/* задаването на стойности по подразбиране тук вече няма да евъзможно така :

Person::Person()  : name(NULL), family(NULL) 

заради наличието на едноименни методи 

*/

Person::Person() {
	/* тук можем да извикаме init(), защото конструкторът Е метод на класа */
	this->init();
}

Person::~Person() {
	/* ... */
	this->destroy();
}

int Person::age(int nage = -1) { 
	if (nage != -1) { 
		this->_age = nage;
	}

	return this->_age;
}

Person::Person(char* nname, char* nfamily ) {
	this->init();

	this->name(nname);
	this->family(nfamily);	
};
