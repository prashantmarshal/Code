#include<iostream>
using namespace std;


class base
{
public:
   	void print ()
    { cout<< "print base class" <<endl; }
 
    void show ()
    { cout<< "show base class" <<endl; }

    virtual ~base(){
    	cout<<"base destructor\n";
    }
};
 
class derived:public base
{
public:
	static int a;

    void print ()
    { cout<< "print derived class" <<endl; }
 
    void show ()
    { cout<< "show derived class" <<endl; }

    ~derived(){
    	cout<<"derived destructor\n";
    }

};

int f(int a){

}

int f(int& a){

}
 
int main()
{
	int g=2;
	f(g);
    derived *bptr = new derived();
    // derived d;
    // bptr = &d;
     
    //virtual function, binded at runtime
    bptr->print(); 
    delete bptr;
    // base &a = d;
    // a.print();
}