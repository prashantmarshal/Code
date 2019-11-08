#include <bits/stdc++.h>

using namespace std;


int arr[10000][10000];
int ROWS, COLS;


// Create prefix array of each column of matrix and return sum in O(1)
int util(int size, int si, int col){
	int sum = 0;

	for (int i = si; i < si + size; ++i){
		sum += arr[i][col];
	}

	return sum;
}


void maximumSumSubMatrix(int rows, int cols){

	int total = -1000, temp;

	for (int size = 1; size <= rows; ++size){

		for(int si = 0; si <= rows - size; ++si){
			temp = -1000;
			for(int y = 0; y < cols; ++y){
				int newsum = util(size, si, y);
				temp = max(temp + newsum, newsum);

				if(total < temp){
					total = temp;
				}
			}
		}
	}

	cout<<total<<endl;
}

int main(){

	int t;
	cin>>t;
	while(t--){
		cin>>ROWS>>COLS;

		{
			for (int j = 0; j < COLS; ++j)
			{
				cin>>arr[i][j];
			}
		}

		maximumSumSubMatrix(ROWS, COLS);

	}
	/*int arr[][COLS] = {{1, 2, -1, -4, -20},
		{-8, -3, 4, 2, 1},
		{3, 8, 10, 1, 3},
		{-4, -1, 1, 7, -6}
	};*/

	/*int rows = sizeof(arr)/sizeof(arr[0]);
	int cols = sizeof(arr[0])/sizeof(arr[0][0]);*/
}

