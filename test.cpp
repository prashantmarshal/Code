
#include <bits/stdc++.h>
using namespace std;

// structure C
typedef struct structc_tag
{
	char    c;
	double   d;
	int 	 s;
} structc_t;

int main()
{
	printf("sizeof(structc_t) = %lu\n", sizeof(structc_t));

	structc_t a,b;
	cout<<&a<<endl;
	cout<<&(a.d)<<endl;
	cout<<&(a.s)<<endl;
	cout<<&b<<endl;

	return 0;
}
