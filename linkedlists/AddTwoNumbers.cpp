#include <bits/stdc++.h>
using namespace std;

 struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
 };

class Solution {
public:

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0, sum = 0;
        ListNode* res = new ListNode();
        ListNode *ret = res;
            
        while(l1 || l2 || carry) {
            sum = carry + (l1 ? l1->val : 0) + (l2 ? l2->val : 0);
            res->next = new ListNode();
            res->next->val = sum % 10;
 
            carry = sum / 10;
            res = res->next;            
            l1 = l1 ? l1->next : l1;
            l2 = l2 ? l2->next : l2;
        }
        
        res = ret->next;
        delete(ret);
        return res;
    }
};  