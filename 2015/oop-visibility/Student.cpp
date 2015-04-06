#include "stdafx.h"
#include "Student.h"

/* този init() знае какво да прави със Student инстанциите... */

void Student::init() {
	cerr << "init Student" << endl;

	/* cerr е специално facility (т.е. обект), който се използва 
	за изход към стандартен поток за грешки... или поток за сервизна
	информация. в случая го използвам, за да го различа от STDOUT, 
	тъй като искам през него да тече информация за работата на приложението,
	а не потребителска информация.

	този обект може лесно да бъде 'пренасочен' към файл например...

	*/

	this->_specialty = new char[MSIZE];

	_specialty[0] = 0;
}

void Student::destroy() {
	delete this->_specialty;
}

Student::Student(void) {

	/* тук не можем да извикаме init() на parent класа. 

	а) защото нитрябва ни собсгвен такъв за Sudent, специфичен за него
	б) защото Parent::init() е умишлено оставен private

	*/

	this->init();	
}


Student::~Student(void) {
	this->destroy();
}

/* в този запис name и family отиват към конструктора на родителския клас" */

Student::Student(char *nname, char* nfamily, char* nspecialty) :
	Person(nname, nfamily) {

	this->init();
	this->specialty(nspecialty);
}

char * Student::specialty(char *nspecialty) {
	if (nspecialty != NULL) { 
		/* тук може да се направи проверка... например за дължина на символния низ */
		int nlen = strlen(nspecialty);
		assert(nlen < MSIZE);
		
		delete _specialty;
		_specialty = new char[strlen(nspecialty) + 1];
		strcpy_s(_specialty, nlen+1, nspecialty);
	}

	return _specialty;
}

/* заб : функционалността изнесена в init() в случая е тривиална. тя може и да се реализира директно
в конструкторите на съотв. класове. но е напълно възможно и други функции да искат да правят същия
вид инициализация...напр. други конструктори или помощни функции. за това общото се изнася в init(), 
макар и в конкретния пример това да е преждевременно действие от гледна точка на процеса на разработка */