#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
		// two majority elements (> n/3)
        vector<int>res;
        
		int c1 = INT_MIN, cnt1 = 0;
		int c2 = INT_MIN, cnt2 = 0;

		for (int i = 0; i < nums.size(); i++)
		{
			if(nums[i] == c1){
				cnt1++;
			} else if(nums[i] == c2){
				cnt2++;
			} else {
				if(cnt1 == 0){
					c1 = nums[i], cnt1 = 1;
				}else if(cnt2 == 0){
					c2 = nums[i], cnt2 = 1;
				} else {
					cnt1--;
					cnt2--;
				}
			}
		}
        
		cnt1 = cnt2 = 0;
		for (int i = 0; i < nums.size(); i++)
		{
			if(nums[i] == c1) cnt1++;
			if(nums[i] == c2) cnt2++;
		}

		if(cnt1 > nums.size()/3){
			res.push_back(c1);
		}
		if(cnt2 > nums.size()/3 && c1 != c2){
			res.push_back(c2);
		}
		
		return res;

    }
};