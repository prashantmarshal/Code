#include <stdio.h>

int avar[1000] = {1}; // data
int bvar; // bss
static int cvar; // bss
static int dvar = 2; // data
static int globalzerostatic = 0; // bss
const int *ptr = &bvar;

void f(){
	int notstatic;
	static int localstatic = 5; // data
	static int zerostatic = 0; // bss
}

/* these strings would be in text, these pointers would be pointing to a text memory */
const char* conststring = "prashant"; // data
char *nonconststring = "patil"; // data
static const char* staticconststring = "prashant"; // data
static char *staticnonconststring = "patil"; // data

int main(){
	static const char* localstaticconststring = "prashant"; // data
	static char *localstaticnonconststring = "patil"; // data
	static int evar = 2; // data
	static int fvar; // bss
}
