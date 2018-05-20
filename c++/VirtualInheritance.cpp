#include <iostream>

using namespace std;

class Base
{
public:
	int b;
	Base(){
		b = 20;
	}
	
};

class Derived1: virtual public Base
{
public:
	int d1;
	Derived1(){
		d1 = 10;
	}
};

class Derived2: virtual public Base
{
public:
	int d2;
	Derived2(){
		d2 = 15;
	}
};

class DD: public Derived1, public Derived2
{
public:
	int dd;
	DD(){
		dd = 30;
	}
};

int main()
{
	DD d;
	int *ptr = (int*)&d;
	cout<<*ptr<<endl;
	ptr++;
	cout<<*ptr<<endl;
	ptr++;
	cout<<*ptr<<endl;
	ptr++;
	cout<<*ptr<<endl;
	ptr++;
	cout<<*ptr<<endl;
	ptr++;
	cout<<*ptr<<endl;
	ptr++;
	cout<<*ptr<<endl;
	ptr++;
	cout<<*ptr<<endl;
	ptr++;
	cout<<*ptr<<endl;

	return 0;
}