#include <iostream>

/*
class BaseClass final
{
public:
	void doSmth()
	{
		std::cout << "BaseClass::doSmth()\n";
	}
};

// Клас, който се опитва да наследи от BaseClass
 //class DerivedClass : public BaseClass
 //{
 //    // грешка по време на компилация
 //};

int main()
{
	BaseClass obj;
	obj.doSmth();
	return 0;
}
*/

/*
class Base
{
	friend class Final;

private:
	Base() { std::cout << "Base::Base()\n"; }
};

class Final : virtual public Base
{
public:
	Final() { std::cout << "Final::Final()\n"; }
};

class Derived : public Final
{
public:
	// грешка по време на компилация
	// конструкторът на виртуалния базов клас не е достъпен
	Derived() { std::cout << "Derived::Derived()\n"; }
};
*/

/*
#include <iostream>

class Base
{
public:
	virtual void canBeOverridden()
	{
		std::cout << "Base::canBeOverridden()\n";
	}

	virtual void cannotBeOverridden() final
	{
		std::cout << "Base::cannotBeOverridden()\n";
	}
};

class Derived : public Base
{
public:
	void canBeOverridden() override
	{
		std::cout << "Derived::canBeOverridden()\n";
	}

	 //void cannotBeOverridden() override
	 //{
	 //    // грешка по време на компилация
	 //    std::cout << "Derived::cannotBeOverridden()\n";
	 //}
};

int main()
{
	Base* b1 = new Base();
	Base* b2 = new Derived();

	b1->canBeOverridden();    // Base::canBeOverridden()
	b1->cannotBeOverridden(); // Base::cannotBeOverridden()

	b2->canBeOverridden();    // Derived::canBeOverridden()
	b2->cannotBeOverridden(); // Base::cannotBeOverridden (не може да бъде предефиниран)

	delete b1;
	delete b2;

	return 0;
}
*/

/*
class Base
{
	friend void friendOfBase(Base& b);
private:
	int pri;

protected:
	int pro;

public:
	Base() : pri(10), pro(20) { }
};

class Derived : public Base
{
private:
	int der_pri;
public:
	Derived() : der_pri(30) {}
	// friendOfBase НЕ Е приятел на Derived
	// Нужен е отделен friend statement в Derived, ако искаме такъв достъп
};

void friendOfBase(Base& b)
{
	std::cout << "friendOfBase():\n";

	std::cout << "Достъп до pri: " << b.pri << std::endl;
	std::cout << "Достъп до pro: " << b.pro << std::endl;

	// b е от тип Base&, не можем да достъп компонент на Derived
	//std::cout << "Достъп до der_pri: " << b.der_pri << std::endl;

	// Ако b e от тип Derived&, пак нямаше да има достъп до der_pri,
	// защото friendOfBase е приятел САМО на Base.
}

int main() {
	Base b;
	Derived d;

	friendOfBase(b);
	// ОК - d може да се подаде като Base&, но в friendOfBase се вижда САМО Base частта
	// friendOfBase(d);

	return 0;
}
*/

// #define <pattern> <replacement>
// 
//// Макроси без параметри
//#define MAX 100
//#define HELLO_MESSAGE "Hello, world!"
//
//// Макроси с параметри
////#define min(a, b) (a < b? a : b)
//#define square(a) ((a) * (a))
//
//#ifdef __cplusplus
//#include <cstdio>
//#else
//#include <stdio.h>
//#endif
//
//#define function(Type)          \
//Type min(Type a, Type b){       \
//return a < b? a : b;            \
//}
//
//function(int)
//function(float)
//
//#include <iostream>
//
//int main_macro()
//{
//    int mi = min(5, 3);
//    std::cout << mi << std::endl;
//
//    float a = 3.5f, b = 4.5f;
//    float mf = min(a, b);
//    std::cout << mf << std::endl;
//
//    float res = min(a + b, b);
//    std::cout << res << std::endl;
//
//    std::cout << HELLO_MESSAGE << std::endl;
//
//    std::cout << square(5) << std::endl;
//
//    int x = 5;
//    std::cout << square(x + 2) << std::endl;
//
//    // square("abc");
//
//    return 0;
//}

#include <iostream>
//#include "Rat.h"

//int min(int a, int b)
//{
//    return a < b ? a : b;
//}
//
//double min(double a, double b)
//{
//    return a < b ? a : b;
//}
//
//const Rat& min(const Rat& a, const Rat& b)
//{
//    return a < b ? a : b;
//}

// какви ограничения налага шаблонът?
template <typename Type>
Type read()
{
	Type value;
	std::cin >> value;
	return value;
}

struct Complex
{
	double re, im;
};

class Student
{
public:
	Student() = default;
	Student(const Student&) = delete;

	bool operator < (const Student&) const
	{
		return false;
	}
};

int min(int a, int b)
{
	std::cout << "Non-template min (" << a << ", " << b << ") = ?";
	if (a < b)
		return a;
	return b;
}

template <typename Type>
const Type& min(const Type& a, const Type& b)
{
	return a < b ? a : b;
}

template <typename Res, typename Type1, typename Type2>
Res sum(Type1 a, Type2 b)
{
	return a + b;
}

// ще предизвика грешка, ако бъде извикана
// ако не бъде генерирана функция по шаблона, 
// всичко ще се компилира
template<typename Type>
Type doNotCall()
{
	Type a = a + 5;
}

int tests()
{
	// обръщение към нешаблонна функция, ако е дефинирана
	// 
	// в противен случай може да предизвика грешка по време 
	// на компилация, тъй като не може да се извлече типа, 
	// за който да се генерира функция по шаблона
	std::cout << min('a', 42.2) << std::endl;

	int i1 = 5, i2 = 7;
	// обръщение към нешаблонна функция,
	std::cout << min(i1, i2) << std::endl;

	// обръщение към функция, генерирана по шаблона
	// типовият параметър се извлича от типа на параметрите
	std::cout << min<>(i1, i2) << std::endl;

	float f1 = 2.3f, f2 = 4.5f;
	// обръщение към функция, генерирана по шаблона
	std::cout << min(f1, f2) << std::endl;

	short sh1 = 1, sh2 = 3;
	// обръщение към функция, генерирана по шаблона
	std::cout << min(sh1, sh2) << std::endl;

	// обръщение към нешаблонна функция
	std::cout << min(i1, sh2) << std::endl;

	unsigned ui = 5u;
	std::cout << min<int>(i1, ui) << std::endl;

	int value = read<int>();

	Complex c1{ 1, 2 }, c2{ 2, 3 };
	// грешка по време на компилация
	//Complex cm = min(c1, c2);

	Student s1, s2;
	min(s1, s2);

	// копиращият конструктор е забранен
	//Student st1 = read<Student>();

	std::cout << "sum = " << sum<double>(2, 3.5) << std::endl;

	return 0;
}

template <typename T>
void print(T value)
{
	std::cout << value << std::endl;
}

// пълна специализация на шаблона
// какво ще се промени, ако специализацията се премести под
// долния шаблон?
//template <>
//void print<>(const char* value)
//{
//    if (value)
//        std::cout << value << std::endl;
//    else
//        std::cout << "nullptr\n";
//}

template <typename T>
void print(T* value)
{
	if (value)
		std::cout << *value << std::endl;
	else
		std::cout << "nullptr\n";
}

// пълна специализация на шаблона
template <>
void print<>(const char* value)
{
	if (value)
		std::cout << value << std::endl;
	else
		std::cout << "nullptr\n";
}

int main_specialization()
{
	print(5);
	print(5.5);

	int x = 42;
	int* px = &x;

	print(px);

	print("abc");

	return 0;
}

int main()
{
	// int res = doNotCall<int>();
	// tests();
	main_specialization();

	return 0;
}