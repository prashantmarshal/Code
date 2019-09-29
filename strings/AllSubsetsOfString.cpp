#include <bits/stdc++.h>
using namespace std;


// Idea is to take an auxiliary buffer data[]
// Put one by one each element arr[i] at a position x in data, and recurs for rest of the elements (i to n-1 with x and beyond space)
// curr for data and index for str 
void util(string str, char data[], int curr, int index, int len){

	for (int i = 0; i < curr; ++i)
		cout<<data[i];
	cout<<endl;

	if(index >= len)
		return;

	for(int i = curr; i < len; ++i){
		data[curr] = str[i];
		util(str, data, curr+1, i+1, len);
		
		/* this is for handling duplicates
		if there were no duplicates we need not sort the string */
		while(str[i+1] == str[i])
			i++;
	}
}

void allcombinations(string str){
	int len = str.length();
	char data[len];

	// this helps in printing in lexicographic order and handle duplicate cases
	sort(str.begin(), str.end());

	util(str, data, 0, 0, len);
}

int main(int argc, char const *argv[]){
	string str = "aab";
	allcombinations(str);
	return 0;
}
