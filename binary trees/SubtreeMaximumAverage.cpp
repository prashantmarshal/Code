// https://www.lintcode.com/problem/597/

class Result {
public:
    int nodes;
    int sum;
    double max_avg;
    TreeNode *node;

    Result(int n=0, int s=0, double m=INT_MIN, TreeNode *N=nullptr) {
        nodes = n; sum = s; max_avg = m; node = N;
    }
};

class Solution {
public:
    Result* util(TreeNode *root) { // {num_nodes, sum, max_avg, node_with_max_avg}
        if(!root) {
            return new Result();
        }

        Result *left = util(root->left);
        Result *right = util(root->right);

        int curr_sum = left->sum + right->sum + root->val;
        int curr_nodes = left->nodes + right->nodes + 1;

        double curr_avg = (double)curr_sum/(double)curr_nodes;
        double max_avg = max(curr_avg, max(left->max_avg, right->max_avg));

        Result *res = new Result(curr_nodes, curr_sum, max_avg, 
                            max_avg == curr_avg ? root:
                            max_avg == left->max_avg ? left->node: 
                            right->node);

        return res;
    }

    TreeNode * findSubtree2(TreeNode * root) {
        return util(root)->node;
    }
};