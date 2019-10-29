#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
    
};

int getMax(Node *p, Node *q){
    if(!p || !q)
        return 0;

    int len = 0;

    while(p && q){
        if(p->data != q->data) {
            break;
        }

        len++;

        p = p->next;
        q = q->next;
    }

    return len;
}

int maxPalindrome(Node *head)
{
    if(!head) return 0;

    Node *curr, *prev, *next;

    curr = head;
    next = head->next;
    prev = NULL;

    int res = 0;
    while(curr){
        curr->next = prev;

        res = max(res, getMax(curr, next)*2);
        res = max(res, getMax(prev, next)*2+1);

        prev = curr;
        curr = next;

        if(next) next = next->next;
    }

    return res;
}