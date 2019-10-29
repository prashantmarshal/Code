#include<iostream> 
using namespace std; 
  
class Derived; 
  
class Base { 
private: 
    virtual void fun() { cout << "Base Fun"; } 
friend int main(); 
}; 
  
class Derived: public Base { 
public: 
    void fun() { cout << "Derived Fun"; } 
}; 
  
  // main function is a friend, hence overriding is possible else compile error
int main() 
{ 
   Base *ptr = new Derived; 
   ptr->fun(); 
   return 0; 
} 