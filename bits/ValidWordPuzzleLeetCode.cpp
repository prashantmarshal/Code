// https://leetcode.com/problems/number-of-valid-words-for-each-puzzle/submissions/

#include <bits/stdc++.h>
using namespace std;


// This is a TLE solution

uint32_t convertToBitMask(string & s){
    uint32_t x = 0;
    for(int i = 0; i < s.size(); i++){
        x = x | (1 << (s[i] - 'a'));
    }
    return x;
}

vector<int> findNumOfValidWords(vector<string>& words, vector<string>& puzzles) {
    
    int size = words.size();
    vector<int> words_bit, puzzles_bit;

    for (int i = 0; i < size; i++)
    {
        words_bit.push_back(convertToBitMask(words[i]));
    }

    size = puzzles.size();

    for (int i = 0; i < size; i++)
    {
        puzzles_bit.push_back(convertToBitMask(puzzles[i]));
    }

    int cnt;
    vector<int> v;

    for (int i = 0; i < puzzles_bit.size(); i++)
    {
        cnt = 0;
        
        char ch = puzzles[i][0];
        for (int j = 0; j < words_bit.size(); j++)
        {
            if(!(words_bit[j] & (1<<(ch-'a'))))
                continue;
            if(((puzzles_bit[i]^words_bit[j]) | puzzles_bit[i]) <= puzzles_bit[i])cnt++;
        }
        v.push_back(cnt);
    }

    return v;
}