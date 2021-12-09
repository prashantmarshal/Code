class Solution {
public:

    int findRightMost1(vector<int> &arr) {
        int l = 0, h = arr.size()-1;
        while(l <= h) {
            int mid = (l+h)/2;
            if(arr[mid] && (mid == arr.size()-1 || arr[mid+1] == 0)) {
                return mid;
            } else if (arr[mid] == 0) {
                h = mid-1;
            } else {
                l = mid+1;
            }
        }
        return -1;
    }

    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        unordered_map<int, queue<int>> freq;

        int Rows = mat.size();
        for (int i = 0; i < Rows; i++) {
            freq[findRightMost1(mat[i])+1].push(i);
        }

        vector<int> res;
        for (int frequency = 0; frequency < Rows; frequency++) {
            if (freq.find(frequency) != freq.end()) {
                queue<int> q = freq[frequency];
                while (!q.empty()) {
                    res.push_back(q.front());
                    if(res.size() == k) return res;
                    q.pop();
                }
            }
        }
        return res;
    }
};