#include <bits/stdc++.h>

using namespace std;

struct s
{
	int z:32;
	long int i: 33;
	long int: 0;
	int a:1;
};

int main(int argc, char const *argv[])
{

	/*int arr[2] = {0, 1};
	s o;
	int *ptr1 = &o.b;
	int *ptr2 = &o.a;
	int k = (unsigned long)ptr2 - (unsigned long)ptr1;//<<endl;
	if(ptr1 + 1 == ptr2)
		cout<<"ok\n";*/
	// cout<<k<<endl;
	// cout<<(unsigned long)arr<<" "<<(unsigned long)&arr[0]<<" "<<(unsigned long)&arr[1]<<" " <<(unsigned long)&arr[1] - (unsigned long)arr<<endl;
/*	int x = 0x80000000;
	cout<<x<<endl;
*/	cout<<sizeof(s)<<endl;
	return 0;
}