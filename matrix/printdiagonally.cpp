#include <bits/stdc++.h>

using namespace std;

void printdiagonal(int arr[5][4], int R, int C){

	int r=0,c=0,counter=0;

	while(counter < R+C-1){
		r = (counter<R)?counter:R-1;
		c = (counter<R)?0:(counter-R+1);
		
		while(r>=0 && c < C){
			cout<<arr[r][c]<<" ";
			r--;c++;
		}
		cout<<endl;
		counter++;
	}

}
int main(){
	int arr[][4] = {
		{1, 2, 3, 4},
		{5, 6, 7, 8},
		{9, 10, 11, 12},
		{13, 14, 15, 16},
		{17, 18, 19, 20}
	};

	printdiagonal(arr, 5, 4);
}

