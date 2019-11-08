// https://www.interviewbit.com/problems/find-a-peak-element/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    
    int findPeakElement(vector<int>& nums) {
        int low = 0, high = nums.size()-1;
        
        while(low < high){
            int mid = (low+high)/2;
            
            if(mid == 0) {
                return nums[0] > nums[1] ? 0 : 1;
            }
            
            if(nums[mid] > nums[mid-1] && nums[mid] > nums[mid+1]){
                return mid;
            }
            
            if(nums[mid] < nums[mid+1]){
                low = mid+1;
            } else {
                high = mid-1;
            }
        }
        
        return low;
    }
};