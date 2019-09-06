#include <iostream>
using namespace std;


class base{
public:
	virtual base* clone(){				// COVARIANT RETURN TYPE AS LONG AS THE RETURN TYPE IS DERIVED FROM BASE CLASS
		printf("this is base class\n");
	}
};

class derived: public base{
public:
	derived* clone(){
		printf("this is derived class\n");
	}
};

void foo(base* obj){
	obj->clone();
}

int main(int argc, char const *argv[]){
	derived *obj = new derived();
	foo(obj);		
	return 0;
}