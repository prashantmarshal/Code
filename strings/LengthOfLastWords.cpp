#include <bits/stdc++.h>
using namespace std;

int lengthOfLastWord(const string A) {
    int len = A.size();

    int x = len-1;

    while(x >= 0 && A[x] == ' ') {
        x--;
    }

    int newx = x;

    while(x >= 0 && A[x] != ' '){
        x--;
    }

    return newx-x;    
}