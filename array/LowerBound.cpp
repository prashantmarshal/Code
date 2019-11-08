#include <bits/stdc++.h>


using namespace std;

int main(){
	int arr[] = {1,2,3,5,6,7};
	int a = lower_bound(arr, arr+6, 4) - arr;
	cout<<a<<endl;
}
