#include<bits/stdc++.h>
using namespace std;

int MaximumSumWithoutAdjacent(int arr[], int n){

	if(n == 1)
		return arr[0];

    // set values for next index (1)
    int incl = 0, excl = arr[0], currmax = arr[0];
    
	for (int i = 1; i < n; ++i){
		currmax = max(incl+arr[i], excl);
        incl = excl;
        excl = currmax;
	}

	return currmax;
}

int main(){
	int t, n;

	cin>>t;

	while(t--){
		cin>>n;

		int arr[n];

		for (int i = 0; i < n; ++i)
			cin>>arr[i];

		cout<<MaximumSumWithoutAdjacent(arr, n)<<endl;
	}
}
