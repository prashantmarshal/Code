#include <bits/stdc++.h>
using namespace std;


int threeSumClosest(vector<int> &nums, int target){
    int n = nums.size();

    sort(nums.begin(), nums.end());
    long int closest_sum;
    
    if (target > 0) {
        closest_sum = INT_MIN;
    } else {
        closest_sum = INT_MAX;
    }

    for (int i = 0; i < n - 2; i++) { 
     
        int j = i + 1, k = n - 1; 

        while (j < k) { 

            int sum = nums[i] + nums[j] + nums[k]; 

            // If the sum is more closer than 
            // the current closest sum 
            if (abs(target - sum) < abs(target - closest_sum)) { 
                closest_sum = sum; 
            } 

            // If sum is greater than target then decrement 
            // the second pointer to get a smaller sum 
            if (sum > target) { 
                k--; 
            } else if (sum < target) {
                j++; 
            } else {
                // optimization - closest_sum == target
                return closest_sum;
            }
        } 
    } 

    // Return the closest sum found 
    return closest_sum; 

}

