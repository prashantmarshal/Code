// https://leetcode.com/problems/remove-duplicates-from-sorted-array/

class Solution {
public:
    int removeDuplicates(vector<int>& arr) {
        int iter = 0;
        for(int i = 0; i < arr.size(); ++i) {
            arr[iter++] = arr[i];
            while(i+1 < arr.size() && arr[i+1] == arr[i]) {
                i++;
            }
        }
        return iter;
    }
};