#include <bits/stdc++.h>

using namespace std;

void printMissing(int arr[], int n){
	bool t[100];
	memset(t, 0, 100);

	for (int i = 0; i < n; ++i)
		if(arr[i] <= 99)
			t[arr[i]] = true;

	int i=0,j=0;

	while(1){
		while(i <= 99 && t[i] == 1)
			i++;

		j = i;

		while(j <= 99 && t[j] == 0)
			j++;

		if(i <= 99){
			cout<<"["<<i<<" "<<j-1<<"]"<<endl;
		}

		i = j;

		if(i > 99)
			break;

	}

}

int main(int argc, char const *argv[])
{
	int arr[] = {88, 98, 1, 3, 2, 99, 0, 10};
	int n = sizeof(arr)/sizeof(arr[0]);
	printMissing(arr, n);
	return 0;
}