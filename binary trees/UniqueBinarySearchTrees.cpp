// https://leetcode.com/problems/unique-binary-search-trees/

class Solution {
public:

    int numTrees(int n) {
        int array[20];
        for (int i = 0; i <= n; i++) {
            arr[i] = -1;
        }

        array[0] = 1, array[1] = 1;
        
        int total = 0;
        for (int i = 2; i <= n; i++) {
            for (int j = 1; j <= i; j++){
                array[i] += array[j-1] * array[i-j];
            }
        }

        return array[n];
    }
};