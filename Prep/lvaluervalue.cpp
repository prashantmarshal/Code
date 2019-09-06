#include <iostream>
using namespace std;

int glob;

int foo_glob(){
	return glob;
}

int& foo_glob_ref(){
	return glob;
}

int main(int argc, char const *argv[])
{
	//foo_glob() = 5; //Error
	foo_glob_ref() = 5;	
	return 0;
}