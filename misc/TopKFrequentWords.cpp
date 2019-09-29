#include <bits/stdc++.h>
using namespace std;

struct OrderByFrequency
{
    bool operator() (const pair<string, int>&a, const pair<string, int>&b){
        // Give priority to frequency. If that is same, give priority to smaller word
        return (a.second > b.second) || (a.second == b.second && a.first < b.first);
    }
};

class Solution {
public:
   
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int>dict;

        for(const auto &word: words) {
            dict[word]++;
        }      


        priority_queue<pair<string, int>, vector<pair<string, int>>, OrderByFrequency> pq;

        vector<string> res;

        for(const auto &pa: dict) {
            pq.push(pa);
            if(pq.size() > k)
                pq.pop();
        }

        int pqsize = pq.size();

        for (int i = 0; i < pqsize; i++)
        {
            res.push_back(pq.top().first);
            pq.pop();
        }
        
        reverse(res.begin(), res.end());
        
        return res;
    }
};