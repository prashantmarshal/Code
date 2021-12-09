class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        // Create a min-heap (min-heap has minimum element at the top, rest all greater than `top`)
        priority_queue<int, vector<int>, greater<int> > pq;

        for (int i = 0; i < nums.size(); i++) {
            pq.push(nums[i]);
            if (pq.size() > k) 
                pq.pop();
        }
        return pq.top();
    }
};


class Solution {
public:

    int quickSort(vector<int> &arr, int l, int r, int k) {

        // swap(arr[r], arr[(l+r)/2]); // To optimize quickSort in a sorted array
        int pivot = arr[r];

        // Partition
        int pos = l;
        for (int i = l; i < r; i++) {
            if (arr[i] > pivot) swap(arr[i], arr[pos++]);
        }
        // pos points to the first element <= pivot
        swap(arr[pos], arr[r]);

        if (pos+1 == k) {
            return arr[pos];
        }

        if (pos+1 < k) {
            return quickSort(arr, pos+1, r, k);
        }
        return quickSort(arr, l, pos-1, k);
    }

    int findKthLargest(vector<int>& nums, int k) {
        // Quick sort
        return quickSort(nums, 0, nums.size()-1, k);
    }
};