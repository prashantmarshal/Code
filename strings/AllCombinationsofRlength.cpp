#include <bits/stdc++.h>

using namespace std;


void util(string str, char data[], int ap, int dp, int al, int dl){

	if(dp >= dl){
		for(int i=0; i<dl; ++i)
			cout<<data[i];
		cout<<endl;
		return;
	}

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


void printalllengthcombinations(string str){
	int len = str.length();
	for (int i = 0; i < len; ++i){
		allcombinations(str, i+1);
	}
}
int main(int argc, char const *argv[]){
	string str = "abc";
	// allcombinations(str, 2);

	printalllengthcombinations(str);
	return 0;
}
