#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int arr[100001];

    int strStr(string haystack, string needle) {
        if(haystack == "" && needle == "")
            return 0;
        
        if(haystack == "")
            return -1;
        if(needle == "")
            return 0;
        
        // Pre process arr
        arr[0] = 0;
        int i=0, j=1;
        int len = needle.length();

        while(j < len){
            if(needle[i] == needle[j]){
                arr[j] = i+1;
                i++; j++;
            } else {
                if(i>=1){
                    i = arr[i-1];
                }else{
                    arr[j] = 0;
                    j++;
                }
            }
        }

        i=0, j=0;
        int cnt = 0;

        int haylen = haystack.length();
        while(i < haylen){
            if(haystack[i] == needle[j]){
                i++;j++;cnt++;
            } else{
                if(j==0){
                    i++;
                }else{
                    j = arr[j-1];
                }
                cnt = j;
            }

            if(cnt == len){
                return i-len;
            }
        }

        return -1;

    }
};