#include <iostream>
using namespace std;

int glob = 10;

const int& f(int x){
	return glob;
}

int main(int argc, char const *argv[])
{
	int a = f(5);
	a=2;
	cout<<a<<endl;
	return 0;
}