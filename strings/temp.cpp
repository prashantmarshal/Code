#include <bits/stdc++.h>

using namespace std;


void util(string str, char data[], int ap, int dp, int al, int dl){

	for (int i = 0; i < dp; ++i)
		cout<<data[i];
	cout<<endl;

	if(dp >= dl)
		return;

	for(int i = ap; i < al; ++i){
		data[dp] = str[i];
		util(str, data, i+1, dp+1, al, dl);
		
		/* this is for handling duplicates
		if there were no duplicates we need not sort the string */
		while(str[i+1] == str[i])
			i++;
	}
}

void allcombinations(string str, int r){
	char data[r];
	int len = str.length();
	sort(str.begin(), str.end());
	util(str, data, 0, 0, len, r);
}

int main(int argc, char const *argv[]){
	string str = "abc";
	allcombinations(str, 3);
	return 0;
}
