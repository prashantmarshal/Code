#include <bits/stdc++.h>
using namespace std;

// interviewbit.com/problems/palindrome-partitioning/

void printAllPalindromes(string str, vector<string> &v, vector<vector<string> > &v2, int index) {
    if (index==str.length()){
        v2.push_back(v);
        return;
    }

    for (int i = index; i < str.length(); i++)
    {
        if(P[index][i]){
            v.push_back(str.substr(index, i-index+1));
            printAllPalindromes(str, v, v2, i+1);
            v.pop_back();
        }
    }
}

bool P[1001][1001];

vector<vector<string> > partition(string str) {

    int n = str.length(); 
    
    memset(P, 0, 1001*1001) ;
    
    int i, j, k, L; // different looping variables 
    
    // Every substring of length 1 is a palindrome 
    for (i = 0; i < n; i++) { 
        P[i][i] = true; 
    } 
    
    /* L is substring length. Build the solution in bottom up manner by 
       considering all substrings of length starting from 2 to n. */
    for (L = 2; L <= n; L++) { 
        // For substring of length L, set different possible starting indexes 
        for (i = 0; i < n - L + 1; i++) { 
            j = i + L - 1; // Set ending index 
            
            // If L is 2, then we just need to compare two characters. Else 
            // need to check two corner characters and value of P[i+1][j-1] 
            if (L == 2) 
                P[i][j] = (str[i] == str[j]); 
            else
                P[i][j] = (str[i] == str[j]) && P[i + 1][j - 1]; 
        } 
    }

    vector<string> v;
    vector<vector<string> >v2;
    printAllPalindromes(str, v, v2, 0);

    return v2;
    
}
