#include <stdio.h>

int avar[1000] = {1}; // data
int bvar; // bss
static int cvar; // bss
static int dvar = 2; // data

int main(){
	static int evar = 2; // data
	static int fvar; // bss
}
