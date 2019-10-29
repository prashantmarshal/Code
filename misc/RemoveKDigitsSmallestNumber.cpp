#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string removeKdigits(string num, int k) {
        // Base conditions
        if(num == "" || k == 0)
            return num;
        
        stack<char> s;

        int i, len = num.length();

        for (i = 0; i < len && k > 0; i++)
        {
            if(s.empty()) {
                s.push(num[i]);
            } else{
                while(!s.empty() && k > 0 && num[i] < s.top()) {
                    s.pop();
                    k--;
                }
                s.push(num[i]);
            }
        }
    
        while(k--){
            // Optimization
            if(s.empty())
                return "0";
            else if(!s.empty()){
                s.pop();
            }
        } 

        // Add numbers in stack and leftout string
        int slen = s.size();
        stack<char>temp;
        for (int i = 0; i < slen; i++)
        {
            temp.push(s.top());
            s.pop();
        }

        slen = temp.size();
        string res = "";

        for (int i = 0; i < slen; i++)
        {
            res += temp.top();
            temp.pop();
        }

        res += num.substr(i, num.length()-i);
        
        // Remove starting 0's, not from 0 itself
        i = 0;
        slen = res.size();
        while(i < slen && res[i] == '0')
            i++;

        // i points to left most index which is non-zero
        return (i == slen) ? "0" : res.substr(i, slen - i);
    }
};