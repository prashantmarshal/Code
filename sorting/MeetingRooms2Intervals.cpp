// https://www.lintcode.com/problem/919/description
/**
 * Definition of Interval:
 * classs Interval {
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

bool Asc(Interval &a, Interval &b) {
    return a.start < b.start;
}

class Solution {
    struct Desc {
        bool operator() (Interval &a, Interval &b) {
            return a.end < b.end;
        }
    };
    
public:
    int minMeetingRooms(vector<Interval> &intervals) {
        sort(intervals.begin(), intervals.end(), Asc);
        priority_queue<Interval, vector<Interval>, Desc> pq; // heap contains ongoing meetings and hence potentially available rooms

        for (auto it: intervals) {
            if(!pq.size()) {
                pq.push(it);
            } else {
                if(pq.top().end <= it.start) {
                    pq.pop();
                }
                pq.push(it);
            }
        }

        return pq.size();
    }
};