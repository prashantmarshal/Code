#include <bits/stdc++.h> 
using namespace std; 

class Dog{
public:
    operator string(){
		return "Dog object assigned to string";
	}
};

int main(int argc, char const *argv[])
{
	string s = Dog();
	cout<<s<<endl; // "Dog object assigned to string" is printed

    Dog d;
    string str = d;
    cout<<str<<endl;

	return 0;
}
