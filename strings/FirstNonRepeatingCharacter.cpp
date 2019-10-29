#include <iostream>
using namespace std;


struct counts
{
	int index = 0;
	int count = 0;
};

int calcSize(char str[]){
	int i=1;
	for(; *(str+i); ++i){
	}
	return i;
}
int firstNonRepeatingCharacter(char *str){

	int size = 256;
	counts hash[size];

	for(int i=0; i<size; ++i){
		hash[str[i]].count++;
		if(hash[str[i]].count == 1)
			hash[str[i]].index = i;
	}

	int index = INT_MAX;

	// If there was only one traversal allowed, we will keep DLL and append new unique elements at the end
	for(int i=0; i<size; ++i){
		if(hash[str[i]].count == 1){
			if(hash[str[i]].index < index)
				index = hash[str[i]].index;
		}
	}

	return index;	

}

int main(int argc, char const *argv[])
{
	char str[] = "geeksforgeeks";
	int index = firstNonRepeatingCharacter(str);
	cout<<"Index: "<<index<<" Character: "<<str[index]<<endl;
	return 0;
}