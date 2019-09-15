#include<bits/stdc++.h>
using namespace std;

void merge(int *a,int n,int *b,int m){
	//Building a min_heap [takes O(m)]
	make_heap(b,b+m,greater<int>());
	
	//This step takes [O(nlogm)]
	for(int i=0;i<n;i++){
		if(a[i]>b[0]){
			//popping from min_heap
			pop_heap(b,b+m,greater<int>());
			
			//Swapping the elements
			int tmp = a[i];
			a[i] = b[m-1];
			b[m-1] = tmp;
			
			//pushing into min_heap
			push_heap(b,b+m,greater<int>());
		}
	}
	//Converting into max_heap b'coz sort_heap() on min heap sorts the array in decreasing order
	//This step is [O(m)]
	make_heap(b,b+m); //It's a max_heap
	
	//This step is O(mlogm)
	sort_heap(b,b+m); //Prooduces array in increasing order
}

int main(){
	int ar1[] = {1, 5, 9, 10, 15, 20};
    int ar2[] = {2, 3, 8, 13};
    int m = sizeof(ar1)/sizeof(ar1[0]);
    int n = sizeof(ar2)/sizeof(ar2[0]);
    merge(ar1, m, ar2, n);
 
    cout << "After Merging nFirst Array: ";
    for (int i=0; i<m; i++)
        cout << ar1[i] << " ";
    cout << "nSecond Array: ";
    for (int i=0; i<n; i++)
        cout << ar2[i] << " ";
   return 0;
}