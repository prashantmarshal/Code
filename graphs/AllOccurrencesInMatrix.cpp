#include <bits/stdc++.h>
using namespace std;

#define ROW 3
#define COL 5

int arr[8][2] = {{0,-1},{-1,-1},{-1,0},{-1,1},{0,1},{1,1},{1,0},{1,-1}};

int cnt = 0;

void printPos(std::vector<pair<int, int> > v, char mat[][COL]){
	int size = v.size();

	for (int i = 0; i < size; ++i){
		cout<<v[i].first<<" "<<v[i].second<<" "<<mat[v[i].first][v[i].second]<<endl;
	}
	++cnt;
	cout<<endl;
}

bool issafe(int a, int b){
	if(a >= ROW || a < 0 || b >= COL || b < 0)
		return false;
	return true;
}

void DFS(char mat[][COL], char *word, int index, int x, int y, vector<pair<int,int> > &pos, int len){
	
	if(index == len+1){
		printPos(pos, mat);
		return;
	}

	for (int i = 0; i < 8; ++i){
		int a = x+arr[i][0],b = y+arr[i][1];

		if(issafe(a,b) && mat[a][b] == word[index]){
			pos.push_back(make_pair(a,b));
			DFS(mat, word, index+1, a, b, pos, len);
			pos.pop_back();
		}
	}

	return;

}

void findWords(char mat[][COL], char *word, int len){

	for(int i = 0; i < ROW; ++i){
		for (int j = 0; j < COL; ++j){
			if(mat[i][j] == word[0]){
				vector<pair<int,int> >pos;
				pos.push_back(make_pair(i,j));
				DFS(mat, word, 1, i, j, pos, len);
			}
		}
	}

}

int main(){
    char mat[ROW][COL]= { {'B', 'S', 'E', 'N', 'S'},
                          {'H', 'E', 'D', 'E', 'S'},
                          {'S', 'G', 'N', 'D', 'E'}
                        };
 
    char word[] ="DEN";
 
    findWords(mat, word, strlen(word) - 1);
    cout<<cnt<<endl;
 
    return 0;
}