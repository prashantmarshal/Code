#include<iostream>
#include<stdlib.h>
using namespace std;

class Test
{
public:
	int a;
	Test()
	{ cout << "Constructor called"; }
};

int main()
{
	Test *t = (Test *) malloc(sizeof(Test));
	t->a = 5;
	cout<<t->a<<endl;
	return 0;
}
