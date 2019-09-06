#include <stdio.h>

struct strct
{
	int a;
	
};

int main(int argc, char const *argv[])
{
    const int a = 0;
    *(int *)&a = 39;
    printf("%d", a);
	return 0;
}