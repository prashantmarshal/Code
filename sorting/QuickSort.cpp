#include <bits/stdc++.h>
using namespace std;


// See FirstMissingPositive for smaller approach
int partition (int arr[], int low, int high)
{
    if(low == high) return low;
    
    int pivot = arr[high];
    int i = 0, j = high-1;

    for(; i<= high-1; ++i){
        if(arr[i]<=pivot) continue;
        while(j > i && arr[j] > pivot){ j--;}
        swap(arr[i], arr[j]);
        if(j <= i) break;
    }
    swap(arr[high], arr[i]);
    
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