#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	int countSubstringsUtil(string s, int left, int right){

	}

    int countSubstrings(string s) {
  		int total = 0;
  		for (int i = 0; i < s.length(); ++i){
			countSubstringsUtil(s, i-1,i+1);
			countSubstringsUtil(s, i,i+1);
		}
    }
};