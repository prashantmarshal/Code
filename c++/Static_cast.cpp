#include<bits/stdc++.h>
#include<string>
using namespace std; 
class Int { 
    int x; 
  
public: 
    Int(int x_in = 0) 
        : x{ x_in } 
    { 
        cout << "Conversion Ctor called" << endl; 
    } 
    operator string() 
    { 
        cout << "Conversion Operator" << endl; 
        return to_string(x); 
    } 
};

int main() 
{
    Int obj = 3;
    string str = obj; 
    obj = 20; 
    string str2 = static_cast<string>(obj); 
    obj = static_cast<Int>(30); 
    return 0; 
} 

/* 
Conversion Ctor called
Conversion Operator
Conversion Ctor called
Conversion Operator
Conversion Ctor called

If assignment operator was not overloaded, B’s constructor is used for assigning bar = foo.
 */