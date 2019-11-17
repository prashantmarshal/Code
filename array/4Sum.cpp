#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
  		sort(nums.begin(), nums.end());
  		std::vector<std::vector<int>> res;

  		if(nums.size() == 0) return res;

  		for (int i = 0; i < nums.size(); ++i)
  		{
            if(i > 0 && nums[i] == nums[i-1])
                continue;
            
  			int a = nums[i];
  			for (int j = i+1; j < nums.size(); ++j)
  			{
                if(j > i+1 && nums[j] == nums[j-1])
                    continue;
                
  				int b = nums[j];

  				// Using two pointer method now
				int start = j+1, end = nums.size() - 1;

				while(start < end) {
					if(nums[start] + nums[end] > target - (a+b)){
						end--;
					}else if(nums[start] + nums[end] < target - (a+b)){
						start++;
					}else {
                		res.push_back(std::vector<int>({a,b,nums[start], nums[end]}));
                        start++;
                        // Avoiding duplicate values for same combination
						while(start < end && nums[start] == nums[start-1])
                            start++;
						end--;
                        while(end > start && nums[end] == nums[end+1])
                            end--;
					}
				}
  			}
  		}
  		return res;
    }
};