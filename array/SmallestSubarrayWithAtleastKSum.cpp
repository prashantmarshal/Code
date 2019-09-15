// https://leetcode.com/problems/shortest-subarray-with-sum-at-least-k/

#include <bits/stdc++.h>
using namespace std;

int p[50001];

int shortestSubarray(vector<int>& A, int K) {
    deque <int> dq;
    int n = A.size();
    int minlen = n+1;

    p[0] = 0;
    for (int i = 1; i <= n; i++)
    {
        p[i] = p[i-1] + A[i];
    }

    for (int i = 0; i <= n; i++)
    {
        while (!dq.empty() && p[dq.back()] >= p[i])
            dq.pop_back();
        
        while (!dq.empty() && p[dq.front()] + K <= p[i]){
            minlen = min(i-dq.front(), minlen);
            dq.pop_front();
        }

        dq.push_back(i);
    }

    return (minlen == n+1)?-1:minlen; 
}

int shortestSubarrayTLE2(vector<int>& A, int K) {
        int n = A.size();
        int prev = 0;
        int minlen = n+1;

        for (int i = 0; i < n; i++)
        {
            p[i] = prev + A[i];
            if (p[i] <= 0) {
                prev = 0;
            } else {
                prev = p[i];
            }
        }
        
        for (int i = 0; i < n; i++)
        {
            if(p[i] >= K) {
                int right = i;
                int currsum = 0;
                while(right >= 0 && p[right] >= 0) {
                    currsum = p[i]-p[right];
                    if(currsum >= K){
                        break;
                    }
                    right--;
                }
                minlen = min(minlen, i-right);
            }
        }
        
        if(minlen == n+1) return -1;
        return minlen;
}

int shortestSubarrayTLE(vector<int>& A, int K) {
        int n = A.size();

        int currsum = 0;
        int currlen = 0, minlen = INT_MAX;

        int left = 0, right = 0;

        while(right < n) {
            currsum += A[right];

            if (currsum <= 0) {
                currsum = 0;
                right++;
                left = right;
                continue;
            }

            if(currsum >= K) {

                // special checking
                int leftR = right, currsumR = 0;
                while(leftR >= left) {
                    currsumR += A[leftR];
                    if(currsumR >= K){
                        currlen = right-leftR+1;
                        minlen = min(minlen, currlen);
                    }
                    leftR--;
                }

                // start moving left in right direction
                while(left <= right && currsum >= K){
                    currlen = right-left+1;
                    minlen = min(minlen, currlen);

                    currsum -= A[left];
                    left++;

                    while (left <= right && A[left] < 0) {
                        currsum -= A[left];
                        left++;
                    }
                }

                // now left points to start of subarray with sum < K
                // it may point ahead of right
            }

            right++;
        }
        if (minlen == INT_MAX)
            return -1;
        return minlen; 
    }