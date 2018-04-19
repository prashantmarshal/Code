#include <iostream>
#include <string.h>
using namespace std;


int main(int argc, char const *argv[])
{
	int x=100, y=50, z=280;
	printf("%c %c %c %c\n", x, y, 80, 1000);
	// Output: d 2 P ? characters whose ascii values are the ones in argument
	const char *string = "helloworld";
	if(string[strlen(string)] == '\0')
		cout<<"Appends null\n";
	else
		cout<<"Doesn't append null\n";
	return 0;
}
