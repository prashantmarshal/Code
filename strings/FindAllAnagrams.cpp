#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> res;
        unordered_map<char, int> countarr;
        unordered_map<char, int> curr;

        for (int i = 0; i < p.length(); ++i)
        	countarr[p[i]]++;

        int count = 0, total = p.length();

        int i = 0;
        for (int j = 0; j < s.length(); ++j)
        {
        	if(countarr[s[j]]){
        		curr[s[j]]++;

        		while (curr[s[j]] > countarr[s[j]]) { // reduce window from left side
                    curr[s[i]]--;
        			i++;
        		}

        		count = j-i+1;
        		if(count == total){
        			res.push_back(i);
        		}
        	} else {
        		i = j+1;
                curr.clear();
        	}
        }

        return res;
    }
};