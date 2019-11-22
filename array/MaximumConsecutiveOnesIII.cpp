#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestOnes(vector<int>& arr, int K) {
		int size = arr.size();

		int start = 0, maxval = 0, curr_count = 0;

		for (int i = 0; i < size; ++i)
		{
			if(arr[i] == 0) {
				curr_count++;
			}

			if(curr_count <= K) {
				maxval = max(i-start+1, maxval);
			}

			while(start <= i && curr_count > K) {
				if(arr[start] == 0) {
					curr_count--;
                }
                start++;
			}
		}

		return maxval;
    }
};	