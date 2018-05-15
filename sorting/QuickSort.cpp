#include <bits/stdc++.h>

using namespace std;


int partition(int arr[], int l, int h){

	int pivot = arr[h];

	int i = l, j = h-1;

	while(i <= j){
		while(i < h && arr[i] < pivot)
			++i;

		while(j >= 0 && arr[j] >= pivot)
			--j;

		if(i < j){
			swap(arr[i], arr[j]);
			i++;
			j--;
		}
	}
	
	swap(arr[i], arr[h]);

	// i will point to the first location that is ahead of smaller elements index
	return i;
}

void quickSort(int arr[], int l, int h){
	
	if(l >= h)
		return;

	int pivot = partition(arr, l, h);

	quickSort(arr, l, pivot-1);
	quickSort(arr, pivot+1, h);

}

int main(int argc, char const *argv[])
{
	int arr[] = {23,4,23,53,4,324,3,4,35,3,2,4,234,3,42,4,23,4,35,34,5,345,43,6,45,6,456,254};
	int n = sizeof(arr)/sizeof(arr[0]);
	quickSort(arr, 0, n-1);
	for (int i = 0; i < n; ++i)
		cout<<arr[i]<<" ";
	cout<<endl;
	return 0;
}