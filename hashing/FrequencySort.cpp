class Solution {
struct Comparator{
    bool operator()(pair<int, char> &a, pair<int, char> &b) {
        if(a.first == b.first) return a.second < b.second;
        return a.first > b.first;
    }
};
public:
    string frequencySort(string s) {
        unordered_map<char, int> freq;
        for (char ch: s) freq[ch]++;

        priority_queue<pair<int, char>, vector<pair<int, char>>, Comparator> pq;
        for (auto it: freq) {
            pq.push(make_pair(it.second, it.first));
        }

        string res = "";
        while (!pq.empty()) {
            pair<int, char> top = pq.top();
            int cnt = top.first;
            while(cnt-- > 0) res += top.second;
        }

        return res;
    }
};