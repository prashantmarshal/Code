#include <bits/stdc++.h>
using namespace std;

int n;

bool issafe(int **arr, int row, int col){

	/*check in left row*/
	for(int i=0;i<col;++i)
		if(arr[row][i] == 1)
			return false;

	/*check in upper diagonal*/
	int r=row,c=col;
	while(r>=0 && c>=0 && r < n && c < n){
		if(arr[r][c] == 1)
			return false;
		r--;c--;
	}

	/*check in lower diagonal*/
	r=row,c=col;
	while(r>=0 && c>=0 && r < n && c < n){
		if(arr[r][c] == 1)
			return false;
		r++;c--;
	}

	return true;

}

bool nqueen(int **arr, int col, int n){
	if(col>=n)
		return true;
	for (int i = 0; i < n; ++i){

		if(issafe(arr, i, col)){
			arr[i][col] = 1;
			if(nqueen(arr, col+1, n))
				return true;
			arr[i][col] = 0;
		}
	}

	return false;

}

int main(int argc, char const *argv[])
{
	int t;
	cin>>t;
	for(int z=0;z<t;++z){
		cin>>n;

		int **arr;
		arr = new int*[n];
		for(int i=0; i<n; ++i){
			arr[i] = new int[n];
			for (int j = 0; j < n; ++j)
				arr[i][j] = 0;
		}

		bool w = nqueen(arr, 0, n);
		if(w){
			cout<<"[";
			for(int i=0;i<n;++i){
				for(int k=0;k<n;++k)
					if(arr[i][k]==1)
						cout<<k+1<<" ";
			}
			cout<<"]\n";
		}else
			printf("-1\n");
	}
	return 0;
}
