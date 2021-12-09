// https://leetcode.com/problems/time-based-key-value-store/

class TimeMap {
    struct Compare{
        bool operator()(const pair<int, string> &a, const pair<int, string> &b) const {
            return a.first < b.first;
        }
    };
public:
    unordered_map<string, set<pair<int, string>, Compare>> m;
    /** Initialize your data structure here. */
    TimeMap() {
    }
    
    void set(string key, string value, int timestamp) {
        m[key].insert(make_pair(timestamp, value));
    }
    
    string get(string key, int timestamp) {
        if (m.count(key) == 0) {
            return "";
        }
        return m[key].lower_bound(pair<int, string> (timestamp, ""))->second;
        // std::set<pair<int, string>, Compare> tmp = m[key];
        // cout<<tmp.size();
        // return tmp.lower_bound(make_pair(timestamp, key))->second;
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */