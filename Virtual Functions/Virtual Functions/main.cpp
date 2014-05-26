#include <iostream>

class Base {
public:
	Base();
	Base(Base const &);
	virtual ~Base();
	const char* GetName() const;
	virtual const char* GetNameVirtual() const;
};

Base::Base()
{
	std::cout << "[0x" << this << "] Entering Base::Base()\n";
}

Base::Base(Base const & other)
{
	std::cout
		<< "[0x"
		<< this
		<< "] Entering Base::Base(Base const &), copying from 0x"
		<< &other
		<< std::endl;
}

Base::~Base()
{
	std::cout << "[0x" << this << "] Entering Base::~Base()\n";
}

const char* Base::GetName() const
{
	return "Base";
}

const char* Base::GetNameVirtual() const
{
	return "Base";
}


class Derived : public Base {
public:
	Derived();
	virtual ~Derived();
	const char* GetName() const;
	virtual const char* GetNameVirtual() const;
};

Derived::Derived()
{
	std::cout << "[0x" << this << "] Entering Derived::Derived()\n";
}

Derived::~Derived()
{
	std::cout << "[0x" << this << "] Entering Derived::~Derived()\n";
}

const char* Derived::GetName() const
{
	return "Derived";
}

const char* Derived::GetNameVirtual() const
{
	return "Derived";
}


void PrintInfo(const char* what, void* addr, const char* name1, const char* name2)
{
	std::cout
		<< "\nEntering "
		<< what
		<< ":\n  object at 0x"
		<< addr
		<< "\n  GetName returns \""
		<< name1
		<< "\"\n  GetNameVirtual returns \""
		<< name2
		<< "\"\n\n";
}


void ByRef(Base& ref)
{
	PrintInfo("ByRef", &ref, ref.GetName(), ref.GetNameVirtual());
}


void ByPtr(Base* p)
{
	PrintInfo("ByPtr", p, p->GetName(), p->GetNameVirtual());
}


void ByValue(Base obj)
{
	PrintInfo("ByValue", &obj, obj.GetName(), obj.GetNameVirtual());
}


int main()
{
	std::cout << "-- Entering main() --\n\n";

	Derived d;

	std::cout << "\n-- Calling functions --\n\n";

	ByValue(d);
	ByRef(d);
	ByPtr(&d);

	std::cout << "\n-- Leaving main() --\n\n";

	return 0;
}
