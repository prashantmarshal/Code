#include <bits/stdc++.h>

using namespace std;

void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}


/*priority queue based*/
int kthsmallestpq(int arr[], int n, int k){

	priority_queue<int, vector<int> > pq;

	int i = 0;

	/*storing first k elements*/
	while(i < k){
		pq.push(arr[i]);
		++i;
	}

	while(i < n){
		int e = pq.top();
		if(arr[i] < e){
			pq.pop();
			pq.push(arr[i]);
		}
		++i;
	}

	return pq.top();

}

int partition(int arr[], int l, int pivot){

	if(l == pivot)
		return l;

	int i = l;
	int k = pivot-1;

	while(i <= k){
		while(arr[i] < arr[pivot]){
			++i;
		}
		while(arr[k] > arr[pivot]){
			--k;
		}
		if(i < k){
			swap(&arr[i], &arr[k]);
			i++;
			k--;
		}else{
			swap(&arr[i], &arr[pivot]);
			break;
		}
	}

	return i;
}


int kthsmallestqs(int arr[], int l, int n, int k){
	int pivot = n-1;
	int pi = partition(arr, l, pivot);
	
	if(pi-l == k-1)
		return arr[pi];

	if(pi >= k) {
		return kthsmallestqs(arr, l, pi, k);
	}else{
		return kthsmallestqs(arr, pi+1, n, k-pi-1);
	}

}


int main(int argc, char const *argv[]){

	int arr[100];
	for (int i = 0; i < 100; ++i){
		arr[i] = i+1;
	}
	int size = sizeof(arr)/sizeof(arr[0]);
	for (int i = 0; i < size; ++i){
		cout<<kthsmallestqs(arr, 0, size, i+1)<<" ";
	}
	cout<<endl;
	for (int i = 0; i < size; ++i){
		cout<<kthsmallestpq(arr, size, i+1)<<" ";
	}
	cout<<endl;
	return 0;
}