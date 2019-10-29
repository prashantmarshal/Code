// leetcode

#include <bits/stdc++.h>
using namespace std;
#define MAXCHAR 256
class Solution {
public:
    string minWindow(string s, string t) {
        int remaining=0;
        int A[MAXCHAR];
        for (int i = 0; i < MAXCHAR; i++) A[i]=0;
        
        for (int i = 0; i < t.size(); i++){
            A[t[i]]++;
            remaining++;
        }
        
        for (int i = 0; i < t.size(); i++){
            if(A[t[i]] <= 0) A[t[i]] = INT_MIN;
        }

        int start = 0, end = -1, final_start = 0, minlen = INT_MAX;
        for (int  i = 0; i < s.size(); i++)     
        {
            char ch = s[i];
            if(A[ch] != INT_MIN){
                A[ch]--;
                if(A[ch]>=0) remaining--;
            }
            
            end = i;
            while(remaining == 0){
                if(minlen > end-start+1){
                    minlen = end-start+1;
                    final_start = start;
                }
                
                if(A[s[start]] == 0){
                    remaining++;
                    A[s[start]]++;
                    start++;
                    break;
                }
                
                if(A[s[start]] == INT_MIN){
                    start++;
                    continue;
                }
                
                if(A[s[start]] < 0){
                    A[s[start]]++;
                    start++;                    
                }
            }
        }
        return (minlen!=INT_MAX)?s.substr(final_start, minlen):"";
    }
};