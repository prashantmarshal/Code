    class Solution {
    public:

        map<string, vector<int>> dp;
        int compute(int x, int y, char op) {
            
            switch (op) {
                case '+':
                    return (x + y);
                case '-':
                    return (x - y);
                default:
                    return (x * y);
            }
        }

        vector<int> util(int low, int high, string s) {
            
            if (dp.find(s.substr(low, high-low+1)) != dp.end()){
                return dp[s.substr(low, high-low+1)];
            }

            vector<int>result;

            for (int i = low; i <= high; i++) {
                if (s[i] == '+' || s[i] == '-' || s[i] == '*') {
                    // recur for left and right portions
                    vector<int> left = util(low, i-1, s);
                    vector<int> right = util(i+1, high, s);

                    for (int x = 0; x < left.size(); x++) {
                        for (int y = 0; y < right.size(); y++) {
                            result.push_back(compute(left[x], right[y], s[i]));
                        }
                    }
                }
            }

            // result empty implies any operator was not present in s[low,high]
            // only number is present
            if (result.empty()) {
                result.push_back(atoi(s.substr(low, high-low+1).c_str()));
            }

            dp[s.substr(low, high-low+1)] = result;
            return result;
        }

        vector<int> diffWaysToCompute(string expression) {
            return util(0, expression.size()-1, expression);
        }
    };