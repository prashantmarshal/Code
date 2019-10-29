#include <bits/stdc++.h>
using namespace std;


class Base
{
public:

};

class Display: public Base
{
public:
	virtual void Display(){
		cout<<"Display\n";
	}
};

class Player: public Base
{
public:
	virtual void Play(){
		cout<<"Play\n";
	}
};

class Derived: public Player, public Display
{
public:
	void Display(){
		cout<<"Display Derived\n";
	}

	void Play(){
		cout<<"Play Derived\n";
	}
	vector<char> v;
	
	
};



int main(int argc, char const *argv[])
{
	Base *ptr = new Derived();
	ptr->Display();
	return 0;
}