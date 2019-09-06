#include <iostream>


const int a;

int main(int argc, char const *argv[])
{
	int *ptr = &a;
	*ptr = 2;	
	return 0;
}