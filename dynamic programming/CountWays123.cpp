#include <iostream>
#include <algorithm>

using namespace std;


long int countWays(long int n){
	long int d[n+1];
	d[0] = 1;
	d[1] = 1;
	d[2] = 2;

	for (long int i = 3; i <= n; ++i)
		d[i] = d[i-1] + d[i-2] + d[i-3];

	return d[n];
}

int main(int argc, char const *argv[])
{
	long int n;
	cin>>n;
	cout<<countWays(n)<<endl;
	return 0;
}