    class Solution {
public:
    
    // Whichever array has smaller sum, try to make its smaller elements to 6, and the array which has larger sum,
    // try to make its larger elements to 1. Repeat till diff is greater than 0.

    int minOperations(vector<int>& nums1, vector<int>& nums2) {
        vector<int> arr1(6+1, 0), arr2(6+1, 0); // count arrays
        int diff = 0, ans = 0;
        for (int i: nums1) diff += i;
        for (int i: nums2) diff -= i;
        
        int i = 1, j = 6;
        
        if(diff < 0) {
            for (int i: nums1) arr1[i]++;
            for (int i: nums2) arr2[i]++;
        }
        return minOperations(nums2, nums1);
        
        diff = abs(diff);
        
        while(i <= 5 && j >= 2 && diff > 0) {
            if (arr1[i] == 0) i++;
            if (arr2[j] == 0) j--;
            
            if(arr1[i] > 0 && arr2[j] > 0) {
                if(abs(i-6) >= abs(j-1)) {
                    diff -= abs(i-6);
                    arr1[i]--; arr1[6]++;
                } else {
                    diff -= abs(j-1);
                    arr2[j]--; arr2[1]++;
                }
                ans++;
            }
        }

        while(i <= 5 && diff > 0) {
            if (arr1[i] == 0) i++;
            diff -= abs(i-6);
            ans++; arr1[i]--; arr1[6]++;
        }
        
        while (j >= 2 && diff > 0) {
            if(arr2[j] == 0) j--;
            diff -= abs(j-1);
            ans++; arr2[j]--; arr2[1]++;
        }
        
        if(diff > 0) return -1;
        return ans;
    }
};