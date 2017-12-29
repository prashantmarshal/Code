#include <iostream>

using namespace std;


int func(string s, int len, int index, int n){
	if(index == len-1){
		return n;
	}
	n *= 10;
	n += s[index]-'0';
	return func(s, len, index+1, n);
}

int main(int argc, char const *argv[]){
	
	string s = "0000";
	int n = 0;
	n = func(s, s.length(), 0, n);
	cout<<n+1<<endl;
	return 0;
}