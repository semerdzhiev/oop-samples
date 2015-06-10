#include <iostream>


///
/// Реализация на шаблона синглетон (singleton)
///
/// Реализацията е "мързелива". Тя създава инстанцията
/// при първата употреба, а не при стартирането на програмата.
///
class Singleton
{
private:
	static Singleton* pInstance;

private:
	Singleton();
	Singleton(Singleton const &);
	Singleton& operator=(Singleton const&);

public:
	static Singleton& GetInstance();
	static void Release();

public:
	int Data;
};

Singleton* Singleton::pInstance = NULL;


Singleton::Singleton()
{
}

Singleton::Singleton(Singleton const &)
{
}

Singleton& Singleton::operator=(Singleton const&)
{
	return *this;
}



///
/// Връща инстанцията (единствената възможна) на класа
///
Singleton& Singleton::GetInstance()
{
	if (pInstance == NULL)
		pInstance = new Singleton;

	return *pInstance;
}


///
/// Освобождава създадената инстанция на синглетона
///
void Singleton::Release()
{
	delete pInstance;
	pInstance = NULL;
}


int main()
{
	Singleton::GetInstance().Data = 10;

	std::cout << Singleton::GetInstance().Data << "\n";

	Singleton::Release();

	return 0;
}