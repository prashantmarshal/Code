#include <iostream>

using namespace std;

void reverseString(string &str, int s, int l){

	int e = s+l-1;

	for (int i = 0; i < l/2; ++i){
		swap(str[s+i], str[e-i]);
	}
}

void reverseWords(string str){

	// Reverse whole string
	reverseString(str, 0, str.length());
	int len = str.length();

	// cout<<str<<endl;
	
	//Reverse words
	int ws = -1, we = -1;

	for (int i = 0; i < len; ++i){
		if(str[i] == ' ' && ws == -1)
			continue;
		else if(str[i] == ' '){
			we = i-1;
			reverseString(str, ws, we-ws+1);
			ws = we = -1;
		}else if(ws == -1){
			ws = i;
		}else if(i == len-1 && ws != -1){
			we = i;
			reverseString(str, ws, we-ws+1);
		}
	}

	cout<<str<<endl;

}

int main(){
	string str = "hello     i am prashant	";
	/*while(1){
		getline(cin, str);
		reverseWords(str);
	}*/
	reverseWords(str);
}