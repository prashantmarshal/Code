// https://leetcode.com/problems/palindromic-substrings/

#include <bits/stdc++.h>
using namespace std;

int d[1001][1001];


// idea is consider every element and the gap between two elements as middle of a probable palindromic substring
int countSubstrings(string s) {
    int num = s.size(); // for 1 lengths

    for(float center = 0.5; center <= s.size()-1; center += 0.5) {
        int left = int(center - 0.5);
        int right = int(center + 1);

        while(left >= 0 && right < s.size() && s[left--] == s[right++])
            ++num;
    }
    return num;
}

string longestPalindromicSubstring(string s) {
    int num = s.size();
    int longest = 1;
    int longest_left = 0;
 
    for(float center = 0.5; center <= num-1; center += 0.5) {
        int left = int(center - 0.5);
        int right = int(center + 1);
 
        while(left >= 0 && right < s.size() && s[left--] == s[right++]){
            if(longest < right-left-1){
                longest_left = left+1;
                longest = right-left-1;
            }
        }
    }
    return s.substr(longest_left, longest);
}

// We will return count as per question
int longestPalindromeSubstr(string s) {
    int n = s.size();
    int cnt = 0;

    for (int i = 0; i < n; i++)
        d[i][i] = 1;

    cnt += n;

    for (int i = 0; i < n-1; i++)
    {
        if(s[i] == s[i+1]){
            d[i][i+1] = 2;
            cnt++;
        }
        else  {
            d[i][i+1] = 1;
        }
    }

    for(int len = 3; len <= n; len++){
        for (int i = 0; i < n-len+1; i++)
        {
            if(s[i] == s[i+len-1]){
                if (len == 3){
                    d[i][i+len-1] = 2 + d[i+1][i+len-2];
                    cnt++;
                }else{
                    if(d[i+1][i+len-2] != 1){
                        d[i][i+len-1] = 2 + d[i+1][i+len-2];
                        cnt++;                    
                    }else
                    {
                        d[i][i+len-1] = 1;
                    }
                }
            }else{
                d[i][i+len-1] = 1;
            }
        }
    }
    return cnt;
}


int main(int argc, char const *argv[])
{
    cout<<longestPalindromicSubstring("abacdfgdcaba");
    return 0;
}
