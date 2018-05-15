#include <bits/stdc++.h>

using namespace std;

// cut a rod in pieces such that product of lengths is maximum


// here d[3] ≠ d[2]*d[1] as cutting a piece of length 2 and 1 further
// might not yield better profit

// hence val[i] = max(earlier_max, (i-j)*j, j*val[i-j])

int maxProd(int n)
{
	int val[n+1];
	val[0] = val[1] = 0;

	for (int i = 1; i <= n; i++)
	{
		int max_val = 0;
		for (int j = 1; j <= i/2; j++)
			max_val = max(max_val, max((i-j)*j, j*val[i-j]));
		val[i] = max_val;
	}
	return val[n];
}

int main(int argc, char const *argv[])
{
	int n;
	cin>>n;
	cout<<maxProd(n)<<endl;
	return 0;
}