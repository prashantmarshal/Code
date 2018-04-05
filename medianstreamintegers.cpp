#include <bits/stdc++.h>

using namespace std;

priority_queue <int> minheap;
priority_queue <int,vector<int>,greater<int> > maxheap;
int median = -1;
int median_curr = -1;

int calculate_median(int n){
	
	if(median == -1){
		
		median = n;
		median_curr = median;

	} else if (n >= median) {
		maxheap.push(n);

		if (minheap.size() + 1 < maxheap.size()) {
			minheap.push(min(median, maxheap.top()));
			median = max(median, maxheap.top());
			median_curr = median;
			maxheap.pop();
		} else if (minheap.size() + 1 == maxheap.size()) {
			median_curr = (median+maxheap.top())/2;
		} else {
			median_curr = median;
		}

	} else {

		minheap.push(n);

		if (minheap.size() > 1 + maxheap.size()) {
			maxheap.push(max(median, maxheap.top()));
			median = max(median, minheap.top());
			median_curr = median;
			minheap.pop();
		} else if (minheap.size() == 1 + maxheap.size()) {
			median_curr = (median+minheap.top())/2;
		} else {
			median_curr = median;
		}
	}

	return median_curr;
}

int main(int argc, char const *argv[])
{
	int n;

	int size = 20;

	int arr[size];

	for (int i = 0; i < size; ++i){
		n = rand()%100;
		arr[i] = n;
		cout<<"Array is : ";
		for(int j=0;j<=i;++j){
			cout<<arr[j]<<" ";
		}
		cout<<endl;
		cout<<"Median is : "<<calculate_median(n)<<endl;
	}	
	return 0;
}