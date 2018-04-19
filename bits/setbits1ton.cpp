#include <bits/stdc++.h>

using namespace std;

int findtwok(int n){
	int cnt = 0;
	int t = 1;

	while(t<=n){
		t *= 2;
		cnt++;
	}
	cnt--;
	return cnt;
}

int findtwop(int p){
	int cnt = 1;

	while(p--){
		cnt *= 2;
	}

	return cnt;
}

int setbits(int n){

	assert(n>=0);
	
	if(n <= 1)
		return n;

	int twok = findtwok(n);
	cout<<"twok is "<<twok<<endl;

	int twop = findtwop(twok);
	cout<<"twop is "<<twop<<endl;

	return twok*twop*0.5 + (n-twop+1) + setbits(n-twop);
}

int main(){
	int n;
	cout<<"Enter number \n";
	cin>>n;

	cout<<setbits(n)<<endl;
}