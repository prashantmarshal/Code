#include <iostream>
using namespace std;

#define total_chars 256

void printOccurrences(string s){
	int len = s.length();
	int arr[total_chars] = {0};

	for(int i=0; i<len;++i)
		arr[s[i]]++;

	for(int i=0;i<total_chars;++i){
		if(arr[i]>0){
			printf("character: %c count: %d\n", i, arr[i]);
		}
	}
}

int main(int argc, char const *argv[])
{

	string s = "thisissomerandomstring123123";
	printOccurrences(s);

}