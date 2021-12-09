class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> result;
        int index = 0;
        while (index < intervals.size() && intervals[index].end < newInterval.start) {
            result.push_back({intervals[index].start, intervals[index++].end});
        }

        while (index < intervals.size() && intervals[index].start <= newInterval.end) {
            newInterval.start = min(newInterval.start, intervals[index].start);
            newInterval.end = max(newInterval.end, intervals[index++].end);
        }
        result.push_back({newInterval.start, newInterval.end});

        while(index < intervals.size()) {
            result.push_back({intervals[index].start, intervals[index].end});
        }

        return result;
    }
};