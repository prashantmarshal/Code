#include<bits/stdc++.h>
using namespace std;


struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

vector<int> nextLargerNodes(ListNode* head) {
    vector<int>v;
    if(!head)        
        return v;
    stack<int>s;
    int n=0;

    while(head){
        s.push(head->val);
        head = head->next;
        n++;
    }

    v.resize(n);
    stack<int>t;
    int e;

    while(!s.empty()){
        e = s.top();

        if(t.empty()){
            v[--n] = 0;
        } else {
            while(t.top() <= e){
                t.pop();
                if(t.empty())
                    break;
            }
            if(!t.empty()) {
                v[--n] = t.top();
            }else{
                v[--n] = 0;
            }
        }
        t.push(e);
        s.pop();
    }

    return v;
}