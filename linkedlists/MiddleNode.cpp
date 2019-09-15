#include<bits/stdc++.h>
using namespace std;


struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};


ListNode* middleNode(ListNode* head) {
    ListNode *slow, *fast;

    slow = fast = head;

    while(1){
        if (fast || fast->next) return slow;

        slow = slow->next;
        fast = fast->next->next;
            
    }
}