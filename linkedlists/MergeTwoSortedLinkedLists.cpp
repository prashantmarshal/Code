#include<bits/stdc++.h>
using namespace std;


 struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(!l1)
            return l2;

        if(!l2)
            return l1;

        ListNode *head = (l1->val > l2->val)?l2:l1;
        ListNode *p = head;

        if(l1->val < l2->val) {
            l1 = l1->next;
        } else {
            l2 = l2->next;
        }

        while(l1 && l2) {
            if (l1->val < l2->val){
                p->next = l1;
                l1=l1->next;
            } else{
                p->next = l2;
                l2=l2->next;
            }
            p = p->next;
        }
        p->next = (!l1)?l2:l1;
        
        return head;
    }
};