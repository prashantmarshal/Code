#include <bits/stdc++.h>
#include <unordered_set>
using namespace std; 


/*

Input: arr[] = {1, 9, 3, 10, 4, 20, 2}
Output: 4
The subsequence 1, 3, 4, 2 is the longest subsequence
of consecutive elements

*/

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> T;

        for(int num: nums) T.insert(num);
        int maxlen = 0;

        for (int i = 0; i < nums.size(); i++)
        {
            if(T.find(nums[i]-1) != T.end()){
                int j = nums[i];
                while(T.find(j) != T.end()) j++;
                maxlen = max(maxlen, j-nums[i]);
            }
        }
        return maxlen;        
    }
};