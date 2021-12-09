class Solution {
public:

    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        // Using partial_sort in STL vector
        partial_sort(points.begin(), points.begin() + k, points.end(),
                     [](vector<int> &a, vector<int> &b) {
                         return (a[0]*a[0] + a[1]*a[1]) < (b[0]*b[0] + b[1]*b[1]);
                     }
        );

        return vector<vector<int>>(points.begin(), points.begin()+k);
    }
};


class Solution {
private:
    struct Comparator {
    public:
        bool operator()(vector<int>& a, vector<int>& b) {
            return (a[0]*a[0] + a[1]*a[1]) < (b[0]*b[0] + b[1]*b[1]);
        }
    };
public:

    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        // Using Max Heap where the top contains the maximum element
        priority_queue<vector<int>, vector<vector<int>>, Comparator> max_heap;

        for (auto point: points) {
            max_heap.push(point);
            if (max_heap.size() > k)
                max_heap.pop();
        }
        
        vector<vector<int>> res;
        while(max_heap.size()) {
            res.push_back(max_heap.top());
            max_heap.pop();
        }
        
        return res;
    }
};