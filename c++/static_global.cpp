#include <iostream>
using namespace std;

class B
{
public:
	int x;
	B(){
		cout<<"B\n";
	}
	
};

class A
{
public:
	static B a;
};

B A::a = B();




int main(int argc, char const *argv[])
{

	A t;
	cout<<t.a.B::x<<endl;	
	return 0;
}