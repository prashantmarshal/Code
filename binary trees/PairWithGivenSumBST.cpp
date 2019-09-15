#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
   int val;
   TreeNode *left;
   TreeNode *right;
   TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


int pairWithGivenSum(TreeNode *root, int sum) {
    if(!root)
        return false;

    stack<TreeNode*>s1;
    stack<TreeNode*>s2;

    bool done1 = false, done2 = false;
    int val1=0,val2=0;
    TreeNode *curr1 = root, *curr2 = root;

    while(true){
        while(done1 == false){
            if(curr1) {
                s1.push(curr1);
                curr1 = curr1->left;
            } else {
                // no left child
                if(s1.empty()){
                    done1 = true;
                }else{
                    curr1 = s1.top();
                    s1.pop();
                    val1 = curr1->val;
                    curr1 = curr1->right;
                    done1 = true; // we got a value from normal traversal to compare
                }
            }
        }


        while(done2 == false){
            if(curr2) {
                s2.push(curr2);
                curr2 = curr2->right;
            } else {
                // no right child
                if(s2.empty()){
                    done2 = true;
                }else{
                    curr2 = s2.top();
                    s2.pop();
                    val2 = curr2->val;
                    curr2 = curr2->left;
                    done2 = true; // we got a value from normal traversal to compare
                }
            }
        }


        if(val1!=val2 && (val1+val2) == sum) {
            return 1;
        }

        if ((val1+val2) > sum){
            done2 = false; //get next node from smaller side traversal
            
        }


        if ((val1+val2) < sum){
            done1 = false; //get next node from larger side traversal
            
        }

        if (val1 >= val2){
            return 0;
        }
    }
}



int main(int argc, char const *argv[])
{
    return 0;
}
