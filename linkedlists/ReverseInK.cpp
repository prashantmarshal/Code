#include<bits/stdc++.h>
using namespace std;


struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};




// reverses remaining k - x nodes also
ListNode* reverseKGroupAll(ListNode* head, int k) {
    if(!head)
        return NULL;

    int kx = k;

    ListNode *prev = NULL, *curr = head, *next = head->next;
    
    while(kx--){
        curr->next = prev;
        prev = curr;
        curr = next;
        if(next) 
            next = next->next;
        else
            break;
    }        

    head->next = reverseKGroupAll(curr, k);
    return prev;
}


// does not reverse remaining nodes
ListNode* reverseKGroup(ListNode* head, int k) {
    if(!head)
        return NULL;
    
    int kx = k;

    ListNode *prev = NULL, *curr = head, *next = head->next;

    // checking k count
    ListNode *chk = head;
    while(kx--) {
        if(chk)
            chk = chk->next;
        else
            break;
    }

    // sublist length < k
    if (kx >= 0) { // as kx-- is done
        return head;
    }
    
    kx = k;
    while(kx--){
        curr->next = prev;
        prev = curr;
        curr = next;
        if(next) 
            next = next->next;
        else
            break;
    }        

    head->next = reverseKGroup(curr, k);
    return prev;
}