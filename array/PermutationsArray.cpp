#include <iostream>
using namespace std;

void swap(int *a, int *b){
	int temp = *a;
	*a = *b;
	*b = temp;
}

void printarray(int arr[], int n){
	for (int i = 0; i <= n; ++i)
	{
		cout<<arr[i]<<" ";
	}
	cout<<endl;
}

void printallcombination(int arr[], int l, int r){
	if(l==r){
		printarray(arr, r);
		return;
	}

	for (int i = l; i <= r; ++i)
	{
		swap(&arr[l], &arr[i]);
		printallcombination(arr, l+1, r);
		swap(&arr[l], &arr[i]);
	}
}

int main(int argc, char const *argv[])
{
	int arr[3] = {1,2,3};
	printallcombination(arr, 0, 2);
	return 0;
}
