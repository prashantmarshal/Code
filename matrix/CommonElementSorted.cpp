#include <bits/stdc++.h>

using namespace std;

#define ROW 4
#define COL 5

int commonElement(int mat[ROW][COL]){

	int cnt = ROW*COL;
	int index, elem;
	int front[ROW];
	memset(front, 0, ROW*sizeof(int));

	while(1){
		index = 0;
		elem = mat[0][front[0]];

		bool same = true;
		for(int i = 1; i < ROW; ++i){
			if(mat[i][front[i]] > elem){
				elem = mat[i][front[i]];
				index = i;
			}
			if(mat[i][front[i]] != mat[i-1][front[i-1]])
				same = false;
		}

		// elem is maximum in fronts, index is corresponding row
		if(same)
			return elem;

		// increment all other fronts
		for (int i = 0; i < ROW; ++i){
			if(mat[i][front[i]] == elem)
				continue;
			if(front[i] == COL-1 && mat[i][front[i]] != elem){
				return -1;
			}
			front[i]++;
		}
	}
}



int main(int argc, char const *argv[])
{
	int mat[ROW][COL] = { {1, 2, 3, 4, 5},
		{2, 4, 5, 8, 10},
		{1, 2, 3, 4, 5},
		{1, 3, 5, 7, 9},
	};

	cout<<commonElement(mat)<<endl;
	return 0;
}
