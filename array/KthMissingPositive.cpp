class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        
        for (int i = 0; i < arr.size(); ++i) {
            if(arr[i] - (i+1) >= k) {
                return i + k; // prev_element + k - (prev_element - (i-1 + 1))
            }
        }
        return arr.size() + k;
    }
};


class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        
        int l = 0, r = arr.size()-1;
        while(l <= r) {
            int mid = (l+r)/2;
            if(arr[mid] - (mid+1) >= k) {
                return + k + mid;
            }
        }
        return arr.size() + k;
    }
};
