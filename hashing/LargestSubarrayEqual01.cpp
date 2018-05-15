#include <bits/stdc++.h>

using namespace std;

int arr[1000];

int largestSubarrayEqual01(int n){
	std::map<int, int> hash;
	int zero = 0, one = 0, diff = 0, len = 0, len_max = 0;
	int s = -1, e = -1;

	hash[0] = -1;

	for (int i = 0; i < n; ++i)
	{
		if(arr[i] == 1){
			one++;
		}else{
			zero++;
		}

		diff = one-zero;

		if(hash.find(diff) == hash.end()){
			hash[diff] = i;
		}else{
			len = i - hash[diff];
			if(len > len_max){
				len_max = len;
				s = hash[diff];
				e = i;
			}
		}
	}

	return len_max;
}


int main(int argc, char const *argv[])
{
	int t, n;
	cin>>t;

	while(t--){
		cin>>n;
		for (int i = 0; i < n; ++i)
			cin>>arr[i];

		cout<<largestSubarrayEqual01(n)<<endl;
	}
	return 0;
}