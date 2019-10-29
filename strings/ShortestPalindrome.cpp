#include <bits/stdc++.h>
using namespace std;

int arr[10001];

class Solution {
public:
    string shortestPalindrome(string s) {
        string res = s;
        int len;

        // Create pre-process array for KMP
        // Reverse and append to original
        reverse(s.begin(), s.end()); 
        // To avoid already palindrome cases
        
        // aa -> aa + aa = aaaa -> length = 3 which is greater than 2
        s = res + "#" + s;
        
        // 0 length from start matches 0 characters from last
        arr[0] = 0;

        int i=0, j=1;

        // Finding longest palindromic prefix
        len = s.length();
        while(j < len){
            if(s[i] == s[j]){
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

        int cnt = arr[len-1];
    
        string res1 = "";
        len = res.length();

        for (int i = 0; i < len - cnt; i++)
        {
            res1 += res[len-1-i];
        }
        
        return res1+res;
    }
};