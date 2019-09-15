#include<bits/stdc++.h>
#include <unordered_set>
using namespace std;

 void bestCandyCrush(string& s, unordered_set<int>& crushed, string& best)
{
    int n = s.length();
    
    // check if we improved the solution
    if (n - crushed.size() < best.length())
    {
        best = "";
        
        for (int i = 0; i < n; ++i)
        {
            if (crushed.count(i) == 0)
                best += s[i];
        }
    }
    
    char prev = 0;
    vector<int> lastMoves;
    
    // try to find some more candies to crush
    for (int i = 0; i < n; ++i)
    {
        for (; i < n; ++i)
        {
            if (crushed.count(i))
                continue;
            
            if (s[i] == prev)
                lastMoves.push_back(i);
            else
                break;
        }
        
        // did it find something?
        if (lastMoves.size() >= 2)
        {
            // remove the new crushed group
            for (int& move: lastMoves)
                crushed.insert(move);
            
            bestCandyCrush(s, crushed, best);
            
            // backtrack
            for (int& move: lastMoves)
                crushed.erase(move);
        }
        
        prev = s[i];
        lastMoves.clear();
        lastMoves.push_back(i);
    }
}


int main() {
    
    string s = "bbbaaabbaaab";
    unordered_set<int> crushed;
    string best = s;
    
    bestCandyCrush(s, crushed, best);
    
    std::cout << "Res: " << best << endl;
} 


/* 

string modifyString(string str) {
    stack<pair<char, int>> s;
    for(int i = 0; i < str.size(); i++) {
        if(s.empty()) s.push(make_pair(str[i], 1));
        else {
            if(s.top().first == str[i] && s.top().second + 1 >= 3) {
                while(!s.empty() && s.top().first == str[i]) s.pop();
            } else {
                s.push(make_pair(str[i], (str[i] == s.top().first ? s.top().second + 1 : 1)));
            }
        }
    }
    string res;
    while(!s.empty()) {
        res = s.top().first + res;
        s.pop();
    }
    return res;
}

int main() {
    vector<string> strs = {"aaabbba"};
    for(string str : strs) {
        cout <<"Input : " << str << " " << "Reduced : " << modifyString(str) <<endl;
    }
} */




/* // Recursively removes adjacent duplicates from str and returns 
// new string. las_removed is a pointer to last_removed character 
char* removeUtil(char *str, char *last_removed) 
{ 
	// If length of string is 1 or 0 
	if (str[0] == '\0' || str[1] == '\0') 
		return str; 

	// Remove leftmost same characters and recur for remaining 
	// string 
	if (str[0] == str[1]) 
	{ 
		*last_removed = str[0]; 
		while (str[1] && str[0] == str[1]) 
			str++; 
		str++; 
		return removeUtil(str, last_removed); 
	} 

	// At this point, the first character is definiotely different 
	// from its adjacent. Ignore first character and recursively 
	// remove characters from remaining string 
	char* rem_str = removeUtil(str+1, last_removed); 

	// Check if the first character of the rem_string matches with 
	// the first character of the original string 
	if (rem_str[0] && rem_str[0] == str[0]) 
	{ 
		*last_removed = str[0]; 
		return (rem_str+1); // Remove first character 
	} 

	// If remaining string becomes empty and last removed character 
	// is same as first character of original string. This is needed 
	// for a string like "acbbcddc" 
	if (rem_str[0] == '\0' && *last_removed == str[0]) 
		return rem_str; 

	// If the two first characters of str and rem_str don't match, 
	// append first character of str before the first character of 
	// rem_str. 
	rem_str--; 
	rem_str[0] = str[0]; 
	return rem_str; 
} 

char *remove(char *str) 
{ 
	char last_removed = '\0'; 
	return removeUtil(str, &last_removed); 
} 

// Driver program to test above functions 
int main() 
{ 
	char str1[] = "bbbaabbaab"; 
	cout << remove(str1) << endl;  

	return 0; 
} 
 */