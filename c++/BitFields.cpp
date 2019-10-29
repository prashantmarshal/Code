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

struct test1
{
        short b: 15; // address 0 byte
        char x: 1; // address 15th bit
        int: 0; // start from next address = address 0 + 4 bytes
        short a: 1; // address 4 byte
};


int main(int argc, char const *argv[])
{
	A *obj = new B();
	cout<<sizeof(test1);
	// D().f2();
	return 0;
}
