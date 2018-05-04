#include <iostream>
#include <algorithm>

using namespace std;

int findMaximumWithoutAlternate(int arr[], int n){
	int d[n];

	if(n == 1)
		return arr[0];

	d[0] = arr[0];
	d[1] = max(d[0], arr[1]);

	for (int i = 2; i < n; ++i){

		d[i] = max(d[i-1], d[i-2]+arr[i]);

	}

	return d[n-1];
}

int main(){
	int t, n;

	cin>>t;

	while(t--){
		cin>>n;

		int arr[n];

		for (int i = 0; i < n; ++i)
			cin>>arr[i];

		cout<<findMaximumWithoutAlternate(arr, n)<<endl;
	}
}
