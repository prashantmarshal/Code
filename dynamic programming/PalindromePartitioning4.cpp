
class Solution {
public:

    bool dp[2002][2002];
    bool isPalindrome[2002][2002];
    
    void populatePalindromes(string &s) {
        memset(isPalindrome, 0, sizeof(isPalindrome));
        for (int i = 0; i < s.size(); i++)
            isPalindrome[i][i] = true;

        for(int L = 2; L <= s.size(); L++) {
            for(int i = 0; i < s.size()-L+1; i++) {
                int j = i+L-1;
                if((L == 2 && s[i] == s[j]) || (s[i] == s[j] && isPalindrome[i+1][j-1])) {
                    isPalindrome[i][j] = true;
                }
            }
        }
    }

    bool util(string s, int index, int parts) {
        if(index == s.size() && parts == 0)
            return true;
        if(index == s.size() || parts == 0)
            return dp[index][parts] = false;

        if(!dp[index][parts]) return false;

        if (parts == 1)
            return dp[index][parts] = isPalindrome[index][s.size()-1];
        
        for (int i = index; i < s.size(); i++) {
            if(isPalindrome[index][i]) {
                if (dp[i+1][parts-1] && util(s, i+1, parts-1)) {
                    return true;
                }
                dp[i+1][parts-1] = false;
            }
        }
        return false;
    }

    bool checkPartitioning(string s) {
        populatePalindromes(s);
        memset(dp, true, sizeof(dp));
        return util(s, 0, 3); // check if s can be divided into 3 palindrome components starting from index 0
    }
};




class Solution {
public:

    bool isPalindrome[2002][2002];
    
    void populatePalindromes(string &s) {
        memset(isPalindrome, 0, sizeof(isPalindrome));
        for (int i = 0; i < s.size(); i++)
            isPalindrome[i][i] = true;

        for(int L = 2; L <= s.size(); L++) {
            for(int i = 0; i < s.size()-L+1; i++) {
                int j = i+L-1;
                if((L == 2 && s[i] == s[j]) || (s[i] == s[j] && isPalindrome[i+1][j-1])) {
                    isPalindrome[i][j] = true;
                }
            }
        }
    }
    
    bool dp[2002][2002];
    bool checkPartitioning(string s) {
        populatePalindromes(s);
        memset(dp, false, sizeof(dp));
        // No partition allowed anymore, hence false
        for (int i = 0; i < s.length(); i++) {dp[i][0] = false;}
        // Partition allowed but no element; can return empty strings, hence true
        for (int i = 0; i <= 3; i++) { dp[0][i] = true; }

        for (int length = 1; length <= s.length(); ++length) {
            for (int k = 1; k <= 3; k++) {
                for (int l = 0; l < length; l++) {
                    dp[length][k] |= dp[l][k-1] && isPalindrome[l][length-1];
                }
            }
        }

        return dp[s.length()][3];
    }
};