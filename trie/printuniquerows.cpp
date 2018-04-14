#include <bits/stdc++.h>

using namespace std;

#define ROW 4
#define COL 5


typedef struct Node{
	bool flag;
	struct Node *child[2]; 
} Node;



Node* newNode(){
	Node* temp = (Node *)malloc(sizeof(Node));
	temp->flag = 0;
	temp->child[0] = temp->child[1] = NULL;
	return temp;
}




bool insert(Node* root, int M[][COL], int row, int col){
	if(root == NULL){
		abort();
	}

	if(col < COL - 1){
		
		if(root->child[M[row][col]] == NULL){
			root->child[M[row][col]] = newNode();
			root->child[M[row][col]]->flag = false;
		}
		
		return insert(root->child[M[row][col]], M, row, col+1);

	} else {
		if(root->child[M[row][col]] == NULL){
			root->child[M[row][col]] = newNode();
			return root->child[M[row][col]]->flag = true;
		}else{
			return false;
		}
	}

	return false;
	
}


void printRow( int (*M)[COL], int row ){
	int i;
	for( i = 0; i < COL; ++i ){
		printf( "%d ", M[row][i] );
	}
	printf("\n");
}



void findUniqueRows( int (*M)[COL] ){
	Node* root = newNode(); 
	int i;

	
	for (i = 0; i < ROW; ++i){
		if (insert(root, M, i, 0)){
			printRow(M, i);
		}
	}
}


int main(){

	int M[ROW][COL] = {{0, 1, 0, 0, 1},
	{0, 0, 0, 0, 1},
	{0,0, 0, 0, 1},
	{1, 0, 1, 0, 0}
};

	findUniqueRows(M);

	return 0;
}

