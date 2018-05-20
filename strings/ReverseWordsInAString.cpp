#include <iostream>

using namespace std;

void reverseString(string &str, int s, int l){

	while(s<l){
			swap(str[s], str[l]);
			s++;
			l--;
	}
}

void reverseWords(string &str){
	int len = str.length();
	reverseString(str, 0, len-1);
	int s = 0, e = 0;

	while(s < len && e < len){

		// search for s
		while(s < len && str[s] == '.'){
			s++;
		}

		if(s == len)
			break;

		e = s;

		while(e < len && str[e] != '.')
			e++;
		reverseString(str, s, e-1);
		s = e;

	}

	cout<<"["<<str<<"]"<<endl;

}

int main(){
	string str = "hello......i..am..prashant....";

	cout<<"["<<str<<"]"<<endl;

	/*while(1){
		getline(cin, str);
		reverseWords(str);
	}*/
	reverseWords(str);
	reverseWords(str);
}
