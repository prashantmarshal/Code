#include<bits/stdc++.h>
using namespace std;

int n, m;

bool isFound(vector<string>& board, int x, int y, string word, int index) {
    if(index == word.length())
        return true;

    if(x < 0 || y < 0 || x >= n || y >= m || board[x][y] != word[index] || board[x][y] == '\0') {
        return false;
    }

    // to not go in reverse direction
    board[x][y] = '\0';

    if(isFound(board, x+1,y, word, index+1) ||
    isFound(board, x,y+1, word, index+1) ||
    isFound(board, x,y-1, word, index+1) ||
    isFound(board, x-1,y, word, index+1)) {
        return true;
    }

    board[x][y] = word[index];

    return false;
}


int Solution::exist(vector<string>& board, string word) {
    if(word == "")
        return true;        

    n = board.size();
    if(n==0)
        return false;

    m = board[0].length();

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if(isFound(board, i, j, word, 0))
                return true; 
        }

    }

    return false;   
}