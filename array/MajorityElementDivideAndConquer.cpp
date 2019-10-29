#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    int findLarger(vector<int>&arr, int low, int high, int left, int right){
        int cnt_left, cnt_right = 0;
        for (int i = low; i <= high; i++)
        {
            if(arr[i] == left) cnt_left++;
            if(arr[i] == right) cnt_right++;
        }
        return cnt_left > cnt_right?left:right;
    }

    int findMajority(vector<int> &arr, int low, int high){
        
        if(low == high) return arr[low];

        int mid = (low+high)/2;
        int left = findMajority(arr, low, mid);
        int right = findMajority(arr, mid+1, high);

        if(left == right) return left;

        //Pick one out of left and right from the whole combined array
        return findLarger(arr, low, high, left, right);
    }

    int majorityElement(vector<int>& nums) {
        return findMajority(nums, 0, nums.size()-1);      
    }
};