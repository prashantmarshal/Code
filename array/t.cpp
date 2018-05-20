#include <bits/stdc++.h>


using namespace std;

int main(){
	int arr[] = {1,2,3,4,5,6};
	int a = lower_bound(arr, arr+6, 2) - arr;
	cout<<a<<endl;
}
