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

class derived1 : public base //public�̳� 
{ 
public:
	void fun() 
	{//derived class���Է���public��protected member  
		std::cout << base::a << base::b << std::endl;
		//  std::cout<<base::c;//���ܷ���  
	}
};
class derived2 : protected base //protected�̳�
{  
public:
	void fun() 
	{//derived class���Է���public��protected member  
		std::cout << base::a << base::b << std::endl;
		// std::cout<<base::c;//���ܷ���  
	}
};
class derived3 : private base //private�̳�
{  
public:
	void fun() 
	{//derived class���Է���public��protected member  
		std::cout << base::a << base::b << std::endl;
		// std::cout<<base::c;//���ܷ���  
	}
};
class derived4 : public derived3 
{//base��member���ܱ�private�̳е���������������  
public:
	void fun() 
	{
		//  std::cout<<a;  
	}
};
class derived5 : base 
{//Ĭ��private�̳�  
	void fun() 
	{//derived class���Է���public��protected member  
		std::cout << base::a << base::b;
		// std::cout<<base::c;//���ܷ���  
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
	std::cout << b1.a;//base class Objectֻ�ܷ���public member  
	std::cout << d1.a;//public�̳�ʱ derived class Objectֻ�ܷ���base class��public member  
	//std::cout<<d1.b<<d1.c;//���ܷ���  
	//std::cout<<d2.a<<d2.b;//protected�̳�ʱ derived class Object�����ʷ�base class��member  
	//std::cout<<d3.a;//private�̳�ʱ derived class Object�����ʷ�base class��member  
	system("pause");
	return 0;
}