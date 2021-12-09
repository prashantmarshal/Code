class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& a, vector<int>& b, int k) {
        priority_queue<pair<int, pair<int, int>>,
                vector<pair<int, pair<int, int>>>,
                greater<pair<int, pair<int, int>>>> pq;

        set<pair<int, int>> hash;

        pq.push(make_pair(a[0]+b[0], make_pair(0, 0)));
        hash.insert(make_pair(0,0));

        vector<vector<int>> res;
        while(k--) {
            int x = pq.top().second.first, y = pq.top().second.second;
            res.push_back({a[x], b[y]});
            pq.pop();

            int x1 = x, y1 = y;
            while(x1 < a.size() && hash.find(make_pair(x1, y)) != hash.end()) {
                x1 = x1+1;
            }
            while(y1 < b.size() && hash.find(make_pair(x, y1)) != hash.end()) {
                y1 = y1+1;
            }

            if(x1 == x && y1 == y)
                continue;

            if(a[x1]+b[y] < a[x]+b[y1]) {
                pq.push(make_pair(a[x1]+b[y], make_pair(x1, y)));
                hash.insert(make_pair(x1, y));
            } else {
                pq.push(make_pair(a[x]+b[y1], make_pair(x, y1)));
                hash.insert(make_pair(x, y1));
            }
        }

        return res;
    }
};