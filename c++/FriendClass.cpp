#include <bits/stdc++.h>

using namespace std;


class A
{
public:
	int a;
	A(){
		a = 10;
	}
};

class B: virtual public A
{
public:
	int b;
	B(){
		b = 15;
	}
};

int main(int argc, char const *argv[])
{

	B b;
	int *ptr = (int*)&b;

	cout<<*ptr<<endl;
	ptr++;
	cout<<*ptr<<endl;
	ptr++;

	cout<<*ptr<<endl;
	ptr++;
	cout<<*ptr<<endl;
	ptr++;
	return 0;
}