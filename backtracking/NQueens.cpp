
struct Pos {
    int x; int y;
    Pos(int x, int y) : x(x), y(y) {}
};

class Solution {
public:

    bool isCompat(Pos &p1, Pos &p2) {
        if(p1.x == p2.x || (abs(p1.x-p2.x) == abs(p1.y-p2.y))) {
            return false;
        }
        return true;
    }
    
    void util(vector<vector<Pos>> &res, vector<Pos> &tmp, int index, int n) {
        if(index == n) {
            res.push_back(tmp);
        } else {
            for (int i = 0; i < n; i++) {
                Pos curr = Pos(i, index);
                bool isCompatible = true;
                for (auto it: tmp) {
                    isCompatible = isCompat(curr, it);
                    if(!isCompatible) {
                        break;
                    }
                }
                
                if(isCompatible) {
                    tmp.push_back(curr);
                    util(res, tmp, index+1, n);
                    tmp.pop_back();
                }
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<vector<Pos>> res;
        vector<Pos> tmp;
        util(res, tmp, 0, n);

        vector<vector<string>> result;
            
        for(auto vec: res) {
            // vec contains positions in form {x,y}
            vector <string> ans(n, string(n, '.'));
            for(auto it: vec) ans[it.x][it.y] = 'Q';
            result.push_back(ans);
        }

        return result;
    }
};