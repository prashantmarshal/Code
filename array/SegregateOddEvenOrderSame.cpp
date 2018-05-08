#include <bits/stdc++.h>

using namespace std;

void segregate(int arr[], int n){
	int i = 0, j = n-1;

	while(i < j){
		while(arr[i]%2 == 1)
			i++;

		while(arr[j]%2 == 0)
			j--;

		if(i < j)
			swap(arr[i], arr[j]);

		i++;
		j--;
	}

	for (int i = 0; i < n; ++i)
		cout<<arr[i]<<" ";
	cout<<endl;
}

void segregateInOrder(int arr[], int n){
	int t[n];

	int i = 0, i2 = 0, j = n-1, j2 = n-1;

	while(i < n){
		if(arr[i]%2 == 1)
			t[i2++] = arr[i];
		i++;
	}

	while(j >= 0){
		if(arr[j]%2 == 0)
			t[j2--] = arr[j];
		j--;
	}

	for (int i = 0; i < n; ++i)
		cout<<arr[i]<<" ";

	cout<<endl;
}

int main(int argc, char const *argv[])
{
	int arr[] = {1,2,4,2,1,5,6,1,3,4,10,3,4,1,3,4,5,4,4,5,5,6,9};
	int n = sizeof(arr)/sizeof(arr[0]);
	sort(arr, arr+n);
	segregateInOrder(arr, n);
	return 0;
}