#include <bits/stdc++.h>

using namespace std;

struct element
{
	int val;
	int row;	
	int col;
};

bool operator<(const element& a, const element& b){
	return a.val > b.val;
}

void kSortedMerge(int arr[][3], int n){

	priority_queue<element> pq;

	element elements[n][n];

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			elements[i][j].val = arr[i][j];
			elements[i][j].row = i;
			elements[i][j].col = j;
		}
	}

	for(int i = 0; i < n; ++i)
		pq.push(elements[i][0]);

	int i = 0;
	element elem;
	while(i < n*n){
		elem = pq.top();
		pq.pop();

		cout<<elem.val<<" ";

		if(elem.col < n-1){
			pq.push(elements[elem.row][elem.col+1]);
		}
		++i;
	}

}


int main(){
	int arr[][3] = {{1, 4, 5},
				{4, 5, 6},
				{7, 8, 9}};

	kSortedMerge(arr, 3);
}