// C program for different tree traversals 
#include <iostream> 
#include<vector>
#include<map>
#include<list>
using namespace std;
/* A binary tree node has data, pointer to left child
and a pointer to right child */
struct Node
{
    int data;
    struct Node* left, * right;
    Node(int data)
    {
        this->data = data;
        left = right = NULL;
    }
};
void getDuplicateSubTrees(struct Node* iTree1, struct Node* iTree2, vector<vector<int> > & ioListCommonSubtrees, list<pair<Node*,Node*> > & ioRemainingSubTrees, int iIndexCommonSubtrees=-1)
{
    if (iTree1 == NULL || iTree2 == NULL)
    {
        if (ioRemainingSubTrees.size() != 0)
        {
            iTree1 = ioRemainingSubTrees.front().first;
            iTree2 = ioRemainingSubTrees.front().second;
            ioRemainingSubTrees.pop_front();
            vector<int> newCommonSubTree;
            ioListCommonSubtrees.push_back(newCommonSubTree);
            iIndexCommonSubtrees = ioListCommonSubtrees.size()-1;
        }
        else
            return;
    }
    if (iTree1->data == iTree2->data)
    {
        if (iIndexCommonSubtrees == -1)
        {
            vector<int> newCommonSubTree;
            ioListCommonSubtrees.push_back(newCommonSubTree);
            iIndexCommonSubtrees = 0;
        }
        ioListCommonSubtrees[iIndexCommonSubtrees].push_back(iTree1->data);
    }
    else
    {
        if (iTree1->left != NULL && iTree2->left != NULL)
            ioRemainingSubTrees.push_back(make_pair(iTree1->left, iTree2->left));
        if (iTree1->right != NULL && iTree2->right != NULL)
            ioRemainingSubTrees.push_back(make_pair(iTree1->right, iTree2->right));
        if (ioRemainingSubTrees.size() != 0 && ioListCommonSubtrees.size() == 0)
        {
            getDuplicateSubTrees(NULL, NULL, ioListCommonSubtrees, ioRemainingSubTrees);
        }
        return;
    }
    /* then recur on left sutree */
    getDuplicateSubTrees(iTree1->left, iTree2->left, ioListCommonSubtrees, ioRemainingSubTrees, iIndexCommonSubtrees);
    /* now recur on right subtree */
    getDuplicateSubTrees(iTree1->right, iTree2->right, ioListCommonSubtrees, ioRemainingSubTrees, iIndexCommonSubtrees);
}
/* Driver program to test above functions*/
int main()
{
    struct Node* root1 = new Node(1);
    root1->left = new Node(2);
    root1->right = new Node(3);
    root1->right->left = new Node(4);
    root1->right->left->left = new Node(7);

    struct Node* root2 = new Node(1);
    root2->right = new Node(3);
    root2->right->left = new Node(7);
    // root2->right->right = new Node(11);
    // root2->left->left = new Node(8);
    // root2->left->right = new Node(5);
    // root2->left->right->right = new Node(7);
    // root2->left->right->right->right = new Node(7);
    // root2->left->right->right->right->left = new Node(1);
    //struct Node* root1 = new Node(1);
    //root1->left = new Node(3);
    //root1->right = new Node(5);
    //root1->right->right = new Node(7);
    //root1->right->right->right = new Node(3);
    //root1->right->right->right->right = new Node(8);
    //root1->left->left = new Node(3);
    //root1->left->right = new Node(4);
    //root1->left->right->left = new Node(4);
    //root1->left->right->left->left = new Node(30000);
    //root1->left->right->left->left->right = new Node(10000);
    //root1->left->right->right = new Node(6);
    //root1->left->right->right->left = new Node(8);
    //root1->left->right->right->right = new Node(6);
    //root1->left->right->right->right->right= new Node(9);
    //struct Node* root2 = new Node(21);
    //root2->left = new Node(3);
    //root2->right = new Node(51);
    //root2->right->right = new Node(7);
    //root2->right->right->right = new Node(3);
    //root2->right->right->right->right = new Node(8);
    //root2->left->left = new Node(3);
    //root2->left->right = new Node(4);
    //root2->left->right->left = new Node(44);
    //root2->left->right->left->left = new Node(30000);
    //root2->left->right->left->left->right = new Node(10000);
    //root2->left->right->right = new Node(6);
    //root2->left->right->right->left = new Node(8);
    //root2->left->right->right->right = new Node(6);
    //root2->left->right->right->right->right = new Node(9);
    vector<int> preOrderTree1;
    vector<int> preOrderTree2;
    vector<vector<int> > ListCommonSubtrees;
    list<pair<Node*, Node*> > RemainingSubTrees;
    //cout << "\nPreorder traversal of binary tree is \n";
    getDuplicateSubTrees(root1, root2, ListCommonSubtrees, RemainingSubTrees);
    cout << "\Common Subtrees : \n";
    vector<int> vec;
        for (int i = 0; i != ListCommonSubtrees.size(); i++)
        {
            if (ListCommonSubtrees[i].size() != 0)
            {
                for (auto itr = ListCommonSubtrees[i].begin(); itr != ListCommonSubtrees[i].end(); itr++)
                    cout << *itr << " ";
            }
            cout << "\n";
        }
    return 0;
}