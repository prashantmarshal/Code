#include <iostream>
using namespace std;

int cnt;

void findcoins(int count, int start, int end, int s[]){
	if(count==0){
		cnt++;
		return;
	}

	if(count<0){
		return;
	}
	if(start>end)
		return;
	cout<<start<<" " <<count<<endl;

	for (int i = start; i < end; ++i){
		findcoins(count-s[i], i, end, s);
		findcoins(count, i+1, end, s);
	}

	return;
}


int main(int argc, char const *argv[])
{
	int count = 8;
	int s[10] = {1,2,3};
	findcoins(count, 0, 2, s);
	cout<<cnt<<endl;
	return 0;
}