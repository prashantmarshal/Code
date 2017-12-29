#include <iostream>
using namespace std;

void f(){
		throw 20;	
}

class T{
public:

	T(){
		cout<<"T constructor\n";
	}

	~T(){
		try{
			cout<<"T destructor\n";
			f();
		}catch(int e){
			cout<<"Exception in destructor caught"<<e<<endl;
		}
	}
};

int main(int argc, char const *argv[])
{
	f();
	try{
		T t1,t2;	
		throw 10;
	}catch (int e){
		cout<<"Exception caught "<<e<<endl;
	}

	return 0;
}