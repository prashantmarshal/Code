class Solution {
private:
    struct Comparator {
        bool operator()(pair<int, pair<int, int>> &a, pair<int, pair<int, int>> &b) {
            return a.first < b.first;
        }
    };
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        priority_queue<pair<int, pair<int, int>>, 
                        vector<pair<int, pair<int, int>>>,
                        Comparator> pq;

        int n = matrix.size();
        if(n == 0) return 0;

        for (int i = 0; i < n; i++)
            pq.push(make_pair(matrix[i][0],
                    make_pair(i, 0));

        int res = 0;
        while(k-- > 0) {
            pair<int, pair<int, int>> top = pq.top();
            res = top.first;
            pq.pop();
            if (top.second.second+1 <= matrix[0].size()-1) {
                pq.push(make_pair(matrix[top.second.first][top.second.second+1],
                        make_pair(top.second.first, top.second.second+1))
        
            }
        }
    }
};