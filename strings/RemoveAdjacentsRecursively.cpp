#include <iostream>

using namespace std;

void printString(string s, int len){
	for (int i = 0; i < len; ++i){
		if(s[i] != '\0')
			cout<<s[i];
	}
	cout<<endl;
}

void trim(string &s, int p, int n){
	// set to null
	cout<<"p "<<p<<" n trim"<<n<<endl;
	for (int i = p; i <= n; ++i){
		s[i] = '\0';
	}

}
void removeadjacentsrecursively(string s){

	int len = s.length();
	if(len <= 1){
		cout<<s<<endl;
		return;
	}

	int p=0, n=1;

	while(1){
		cout<<"p "<<p<<" n "<<n<<endl;
		if(s[p] == s[n]){
			// find farthest n such that s[p] == s[n]
			++n;
			if(n == len){
				trim(s, p, n-1);
				printString(s, len);
				return;
			}
			while(s[p] == s[n] && n < len)
				++n;
			trim(s, p, n-1);


			// resetting p and n
			p--;
			while(s[p] == '\0' && p >= 0){
				p--;
			}

			p = (p != 0 || s[p] != '\0')?p:n;
			n = (p==n)?n+1:n;

			if(n == len){
				printString(s, len);
				return;
			}
		}else{
			p++;
			while(s[p] == '\0')
				p++;
			n++;
			if(n == len){
				printString(s, len);
				return;
			}
		}
	}
}

int main(){
	string s;
	while(1){
		getline(cin, s);
		removeadjacentsrecursively(s);
	}
}