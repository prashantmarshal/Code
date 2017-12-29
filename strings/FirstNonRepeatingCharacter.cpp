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
	counts countarr[size];

	for(int i=0; i<size; ++i){
		countarr[str[i]].count++;
		if(countarr[str[i]].count == 1)
			countarr[str[i]].index = i;
	}

	int index = INT_MAX;

	for(int i=0; i<size; ++i){
		if(countarr[str[i]].count == 1){
			if(countarr[str[i]].index < index)
				index = countarr[str[i]].index;
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