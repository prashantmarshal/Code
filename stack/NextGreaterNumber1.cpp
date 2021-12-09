class Solution {
public:

    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> result;
        unordered_map<int, int> nGreater;
        stack<int> s;

        for (int i = 0; i < nums2.size(); i++) {
            while(!s.empty() && nums2[i] > nums2[s.top()]) {
                nGreater[nums2[s.top()]] = nums2[i];
                s.pop();
            }
            s.push(i);
        }
    
        for (int i = 0; i < nums1.size(); i++) {
            result.push_back(nGreater.find(nums1[i]) != nGreater.end() ? nGreater[nums1[i]] : -1);
        }
        return result;
    }
};