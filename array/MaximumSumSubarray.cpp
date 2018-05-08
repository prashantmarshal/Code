#include <bits/stdc++.h>

using namespace std;

int arr[10000];

// kadane
int maxSubarray(int n){
	if(n==0) return 0;

	int curr = arr[0];
	int total = arr[0];

	for (int i = 1; i < n; ++i)
	{
		curr = max(curr+arr[i], arr[i]);
		total = max(total, curr);
	}

	return total;

}


int main(int argc, char const *argv[])
{
	int t;
	cin>>t;
	int n;
	while(t--){
		cin>>n;
		for (int i = 0; i < n; ++i)
			cin>>arr[i];

		cout<<maxSubarray(n)<<endl;
	}
	return 0;
}