class Solution {
private:
    struct Comparator {
        bool operator()(pair<int, int> &a, pair<int, int> &b) {
            return a.second > b.second; // Descending order
        }
    };
    
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        /* unordered_map<int, int> freq;
        for (auto num: nums) freq[num]++;

        priority_queue<pair<int, int>, vector<pair<int, int>>, Comparator> min_heap;
        for (auto key: freq) {
            min_heap.push(make_pair(key.first, key.second));
            if (min_heap.size() > k)
                min_heap.pop();
        }

        vector<int> res;
        while(min_heap.size()) {
            res.push_back(min_heap.top().first);
            min_heap.pop();
        }

        return res; */
        
        unordered_map<int, int> freq;
        for (auto num: nums) freq[num]++;
        unordered_map<int, vector<int>> buckets;
        for (auto key: freq) buckets[key.second].push_back(key.first);

        vector<int> res;
        for(int frequency = nums.size(); frequency >= 1; frequency--) {
            if (buckets.find(frequency) != buckets.end()) {
                for (auto e: buckets[frequency]) {
                    if(k-- <= 0) break;
                    res.push_back(e);
                }
            }
        }

        return res;
    }
};