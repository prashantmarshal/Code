#include <bits/stdc++.h>
using namespace std;


void createTemporaryArray(string pattern, int *array){
	int i=1,j=0;
	array[0] = 0;
	for(;i<pattern.length();){
		if(pattern[i] == pattern[j]){
			array[i] = array[j]+1;
			++i;
			++j;
		}else{
			if(j!=0){
				j = array[j-1];
			}else{
				array[i] = 0;
				i++;
			}
		}
	}
}

int KMPsearch(string text, string pattern){
	int array[pattern.length()];
	createTemporaryArray(pattern, array);
	
	int j=0;
	int len=0, max=0;
	for(int i=0; i<text.length();){
		if(text[i]==pattern[j]){
			++i;
			++j;
			++len;
			max = (len>max)?len:max;
		}else{
			if(j!=0){
				j = array[j-1];
			}else{
				++i;
			}
			len = j;
		}
	}
	if(j==pattern.length())
		printf("Found\n");
	cout<<max<<endl;
	return max;
}

int main(int argc, char const *argv[])
{
	string text = "heymynameisprashantpatilwhatareyoudoing";
	string pattern;
	cin>>pattern;
	cout<<"Index "<<KMPsearch(text, pattern)<<endl;
	return 0;
}