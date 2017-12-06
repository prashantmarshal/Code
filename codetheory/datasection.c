#include <stdio.h>

int avar[1000] = {1}; // data
int bvar; // bss
static int cvar; // bss
static int dvar = 2; // data
static int dvar = 2; // data
static int globalzerostatic = 0; // bss

void f(){
       int notstatic;
       static int localstatic = 5; // data
       static int zerostatic = 0; // bss
}

int main(){
	static int evar = 2; // data
	static int fvar; // bss
}
