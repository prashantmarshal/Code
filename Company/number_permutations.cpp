#include <iostream>
using namespace std;

void swap(int *array, int x, int y){
	int temp = array[x];
	array[x] = array[y];
	array[y] = temp;
}

void do_permutation(int array[], int size, int index){
	
	if(index == size-1){
		for (int i = 0; i <= index; ++i)
			cout<<array[i]<< " ";
		cout<<endl;
	}

	for(int i = index; i < size; ++i){
		swap(array, index, i);
		do_permutation(array, size, index+1);
		swap(array, i, index);
	}

}

int main(int argc, char const *argv[])
{
	int array[] = {11,12,13};
	do_permutation(array, sizeof(array)/sizeof(array[0]), 0);
	return 0;
}