#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	string removeDuplicateLetters(string s) {
		if(s == "") return s;

		stack<char>st;
		unordered_map<char, int> present;
		unordered_map<char, int> used;

		for(int i=0; i<s.length(); ++i){
			present[s[i]]++;
		}

		for(int i=0; i<s.length(); ++i){
			if(st.empty()){
				st.push(s[i]);
				used[s[i]]++;
				present[s[i]]--;
			} else {
				if(used[s[i]]) {
					present[s[i]]--;
					continue;
				}

				while(!st.empty() && st.top() > s[i] && present[st.top()] > 0) {
					used[st.top()]--;
					st.pop();
				}
				st.push(s[i]);
				present[s[i]]--;
				used[s[i]]++;
			}
		}        

		stack<char>st_util;
		while(!st.empty()){
			st_util.push(st.top());
			st.pop();
		}

		string res = "";
		for(int i=0; !st_util.empty(); ++i){
			res += st_util.top();
			st_util.pop();
		}
		return res;
	}
};