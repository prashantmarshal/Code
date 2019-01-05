#include <bits/stdc++.h>

using namespace std;

struct test
{
unsigned int x; 
long int y: 31;
unsigned int z;
};

struct s
{
int *z;
int x;
};

class A {
public:
	int a;

	A(){
		a = 5;
	}
};

class B: public A
{
public:
	int a;
	B(){
		a = 10;
	}
	
};


int main(int argc, char const *argv[])
{
	A *obj = new B();
	cout<<obj->a;
// D().f2();
return 0;
}
