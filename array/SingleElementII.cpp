// https://leetcode.com/problems/single-number-ii/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int result = 0;  
        int x, sum;  
        for (int i = 0; i <32; i++){  
            sum = 0;  
            x = (1 << i);  
            for (int j = 0; j <nums.size(); j++ ){  
                if (nums[j] & x)  
                    sum++;  
            }  
            if (sum % 3)  
                result |= x;  
        } 
        return result;
    }
};