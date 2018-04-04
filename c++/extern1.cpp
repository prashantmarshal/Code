#include <stdio.h>
#include <iostream>
#include "extern2.cpp"

using namespace std;

extern int a;

int main(){
	a = 10;
	cout<<a<<endl;
	cout<<foo()<<endl;
}
