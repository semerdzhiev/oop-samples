// oop-visibility.cpp : Defines the entry point for the console application.
//


#include "stdafx.h"

using namespace std;

/* ще реализираме прост клас, който включва методи и  атрибути с различна видимост */

/* в този заглавен файл (header) е само прототипа на класа и методите... */

#include "Person.h"
#include "Student.h"

int main() {
	/* ако конструктора не е public (видим) няма да можем да инстанцираме  */

	Person pinst;
	Student sinst("Gheorghi", "Penkov", "Informatics");
	
	// sinst съдържа всички данни от pisnt и може да ползва методите му

	/* подобно извикване: 
	
	pinst.init();

	ще предизвиква грешка, защото init() не е видим за "външния свят"
	можем да извикаме този метод само, чрез друг метод на класа, ... например конструтора */

	/* това ще изведе грешка... както се очаква. променливата е скрита : 

		strcpy(pinst._name, "Тестан");

	за това използваме 'setter' метода
	
	*/

	/* подобна операция 

		sinst._age = 10;

	не е възможна, защото _age е protected, което прави променливата видима в наследния клас,
	но невидима за останалия свят 

	*/

	pinst.name("Iliya");
	pinst.family("Rankov");

	cout << "pinst visual representation : " << pinst << endl;

	// защо работи това ?! 

	cout << "sinst visual representation : " << sinst << endl;		

	/* защото имаме оператор, чиито десен операнд е нещо от тип Person, 
	но понеже Student -is-a- Person, можем да приложим оператора */

	cout << "please input new name for person (pinst instance): ";
	cin >> pinst;
	cout << "data read from STDIN : " << pinst; 

	return 0;
}

