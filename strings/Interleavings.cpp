#include <bits/stdc++.h>

using namespace std;

void interleavings(string s1, string s2, string str, int l1, int l2, int i1, int i2){

	if(i1 > l1 && i2 > l2){
		cout<<str<<endl;
	}

	if(i1 <= l1 && i2 <= l2){
		interleavings(s1, s2, str+s1[i1], l1, l2, i1+1, i2);
		interleavings(s1, s2, str+s2[i2], l1, l2, i1, i2+1);
	}else if(i1 <= l1){
		interleavings(s1, s2, str+s1[i1], l1, l2, i1+1, i2);
	}else if(i2 <= l2){
		interleavings(s1, s2, str+s2[i2], l1, l2, i1, i2+1);
	}
}

int main(int argc, char const *argv[])
{
	string s1 = "ab";
	string s2 = "cd";
	string str;
	interleavings(s1, s2, str, s1.length()-1, s2.length()-1, 0, 0);
	return 0;
}