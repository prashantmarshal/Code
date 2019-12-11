#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
  		
  		int low = 0, high = nums.size()-1, mid;

  		while(low <= high) {
  			mid = (low+high)/2;

  			if(mid == 0 || mid == high) return mid;

  			if(mid%2 && nums[mid] == nums[mid-1]){
  				low = mid+1;
  			} else if(mid%2 == 0 && nums[mid] == nums[mid+1]) {
  				low = mid+1;
  			} else{
  				high = mid-1;
  			}
  		}

  		return mid;
    }
};