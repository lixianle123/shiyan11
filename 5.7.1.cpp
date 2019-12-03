//example5_07.cpp: 基类构造函数调用举例
#include <iostream>
#include<Windows.h>
using namespace std;

class Base
{
private:
	int x;
public:
	Base(int i)
	{
		x = i;
		cout << "constructing Base\n";
	}
	void show()
	{
		cout << " x = " << x << endl;
	}
};

class Derived(int t):d(i)
{
	Base (i);
		cout << "constructing Derived\n";
};

int main()
{
	Derived obj(100);
	obj.show();
	system("pause");
	return 0;
}