#include <iostream>  
#include <windows.h>
using namespace std;

class base {
public:
	base() {
		a = 0;
		b = 1;
		c = 2;
	}
	int a;
protected:
	int b;
private:
	int c;
};

class derived1 : public base //public继承 
{ 
public:
	void fun() 
	{//derived class可以访问public和protected member  
		std::cout << base::a << base::b << std::endl;
		//  std::cout<<base::c;//不能访问  
	}
};
class derived2 : protected base //protected继承
{  
public:
	void fun() 
	{//derived class可以访问public和protected member  
		std::cout << base::a << base::b << std::endl;
		// std::cout<<base::c;//不能访问  
	}
};
class derived3 : private base //private继承
{  
public:
	void fun() 
	{//derived class可以访问public和protected member  
		std::cout << base::a << base::b << std::endl;
		// std::cout<<base::c;//不能访问  
	}
};
class derived4 : public derived3 
{//base的member不能被private继承的派生类的子类访问  
public:
	void fun() 
	{
		//  std::cout<<a;  
	}
};
class derived5 : base 
{//默认private继承  
	void fun() 
	{//derived class可以访问public和protected member  
		std::cout << base::a << base::b;
		// std::cout<<base::c;//不能访问  
	}
};
int main(void)
{
	base b1;
	derived1 d1;
	derived2 d2;
	derived3 d3;
	d1.fun();
	d2.fun();
	d3.fun();
	std::cout << b1.a;//base class Object只能访问public member  
	std::cout << d1.a;//public继承时 derived class Object只能访问base class的public member  
	//std::cout<<d1.b<<d1.c;//不能访问  
	//std::cout<<d2.a<<d2.b;//protected继承时 derived class Object不能问访base class的member  
	//std::cout<<d3.a;//private继承时 derived class Object不能问访base class的member  
	system("pause");
	return 0;
}