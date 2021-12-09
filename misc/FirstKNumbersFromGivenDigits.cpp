#include <bits/stdc++.h>
#include <vector>
#include <queue>

using namespace std;

void printNumber(vector<int> numbers) {
    for (int i = 0; i < numbers.size(); i++) {
        cout << numbers[i];
    }
    cout<<" ";
}

void generateNumbers(vector<int>digits, vector<int>number, int &k, int size, int &count) {
    if(number.size() == size) {
        printNumber(number);
        k--;
        return;
    }

    for (int i = 0; i < digits.size(); i++) {
        if (k <= 0) {
            return;
        }

        number.push_back(digits[i]); 
        generateNumbers(digits, number, k, size, count);
        number.pop_back();
    }
}

void printFirstK(vector<int>digits, int k) {
    vector<int>number;
    
    int count = 0, size = 1;
    while (k > 0) { // keep generating numbers of 'size' sizes until the limit 'k' is reached
        generateNumbers(digits, number, k, size, count);
        size++;
    }
}


void printFirstKQueue(vector<int> digits, int k) {
    queue<int>q;
    for (int i = 0; i < digits.size(); i++) {
        q.push(digits[i]);
    }

    while(!q.empty() && k-- > 0) {
        int x = q.front();
        printf("%d ", x);
        q.pop();
        for (int i = 0; i < digits.size(); i++) {
            q.push(x*10+digits[i]);
        }
    }
}

int main(int argc, char) {
    vector<int> digits;
    digits.push_back(1);
    digits.push_back(2);
    digits.push_back(3);

    int k = 20;
    printFirstK(digits, k);
    printf("\n");
    k = 20;
    printFirstKQueue(digits, k);
}