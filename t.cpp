#include <stdio.h>
#include <iostream>

using namespace std;


#include <string.h>

/*void foo (char *bar)
{
   char  c[12];

   strcpy(c, bar);  // no bounds checking
}

int main (int argc, char **argv)
{
   foo(argv[1]);

   return 0;
}*/

class T{
	void f(){
		int a;
	}
};

int main(){
	cout<<sizeof(T);
}