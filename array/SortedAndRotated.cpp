#include <bits/stdc++.h>
using namespace std;

int arr[1000];

int searchUtilIterative(vector<int>& nums, int target, int low, int high) {
	while(low <= high){
		int mid = (low+high)/2;
		if (nums[mid] == target) return mid;

		if(nums[low] <= nums[mid]) {
			if (target >= nums[low] && target <= nums[mid]) {
				high = mid-1;
			} else {
				low = mid+1;
			}
		} 
		// if mid to high is sorted
		else if (nums[mid] <= nums[high]) {
			if (target >= nums[mid] && target <= nums[high]) {
				low = mid+1;
			} else {
				high = mid-1;
			}
		}
	}
	
	return -1;
}

int searchUtil(vector<int>& nums, int target, int low, int high) {
	if(low>high) return -1;

	int mid = (low+high)/2;

	if (nums[mid] == target) return mid;

	// if low to mid is sorted
	if(nums[low] <= nums[mid]) {
		if (target >= nums[low] && target <= nums[mid]) {
			return searchUtil(nums, target, low, mid-1);
		} else {
			return searchUtil(nums, target, mid+1, high);
		}
	} 
	// if mid to high is sorted
	else if (nums[mid] <= nums[high]) {
		if (target >= nums[mid] && target <= nums[high]) {
			return searchUtil(nums, target, mid+1, high);			
		} else {
			return searchUtil(nums, target, low, mid-1);
		}
	}
}

int search(vector<int>& nums, int target) {
	int size = nums.size();
	int low = 0, high = size-1;

	return searchUtil(nums, target, low, high);

}
