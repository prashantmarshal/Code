#include <iostream>
using namespace std;

class base
{
public:
	virtual void print(){
		printf("base\n");
	}
	
};

class derived: public base
{
public:
	void print(){
		printf("derived\n");
	}
};

void foo(base b){
	b.print();
}

int main(int argc, char const *argv[])
{
	derived obj;
	foo(obj);	
	return 0;
}