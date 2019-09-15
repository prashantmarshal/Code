#include<bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* reverseList(ListNode* head) {
    if(!head)
        return head;
    
    ListNode *prev = NULL, *curr = head, *next = head->next;
    
    while(curr){
        curr->next = prev;
        prev = curr;
        curr = next;
        
        if (next) next = next->next;
    }
    
    return prev;  
}

ListNode* reverseUtil(ListNode *curr, int n){
    ListNode *prev = NULL, *next = curr->next, *curr2 = curr;
    
    while(curr && n--){
        curr->next = prev;
        prev = curr;
        curr = next;
        
        if (next) next = next->next;
    }

    if(curr)
        curr2->next = curr;

    return prev;
}

ListNode* reverseListMtoN(ListNode* head, int m, int n) {
    if(!head)
        return head;
    
    ListNode *prev = NULL, *curr = head, *next = head->next;
    
    n = n-m+1; // these many nodes to be reversed
    m--;

    while(m--){
        prev = curr;
        curr = curr->next;
        if(!curr) return head;
    }
    
    ListNode *ret = reverseUtil(curr, n);
    if(prev) 
        prev->next = ret;
    else 
        return ret;
    
    return head;  
}