#include <iostream>
using namespace std;

int arr[2000];

void minimumSubarrayMoreThanK(int n, int k){
	int i = 0, j = 0, len = 10000;
	int sum = 0;

	while(i < n){
		sum += arr[i];
		if(sum > k){
			len = min(len, i-j+1);

			while(j <= i){
				sum -= arr[j];
				j++;
				if(sum > k){
					len = min(len, i-j+1);
				}
				else
					break;
			}
		}
		++i;
	}
	
	cout<<len<<endl;

}


int main(int argc, char const *argv[])
{
	int t, n, k;
	cin>>t;
	while(t--){
		cin>>n>>k;

		for (int i = 0; i < n; ++i)
			cin>>arr[i];
		minimumSubarrayMoreThanK(n, k);
	}
	return 0;
}
