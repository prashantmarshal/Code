#include <iostream>
using namespace std;


void permuteUtil(string s, int start, int len){

	for(int i=0;i<start;++i){
		cout<<s[i];
	}
	cout<<endl;
	if(start == len){
		//cout<<s<<endl;
		return;
	}

	for(int i=start; i<len; ++i){
		swap(s[start], s[i]);
		permuteUtil(s, start+1, len);
		swap(s[i], s[start]);
	}
}


void permute(string s){
	int len = s.length();
	permuteUtil(s, 0, len);

}

int main(int argc, char const *argv[])
{
	string s = "456";
	permute(s);
	return 0;
}
