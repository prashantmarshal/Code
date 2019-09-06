#include <iostream>
using namespace std;

class A
{
public:
	virtual void play(){
		printf("This is play in base\n");
	}

	virtual void study() = 0;
	
};

class D: public A
{
public:
	void play(){
		printf("This is play in derived\n");
	}

	void study(){
		printf("This is study in derived\n");
	}
	
};

int main(void)
{
	A *obj = new D();
	obj->play();
	printf("Program\n");
}