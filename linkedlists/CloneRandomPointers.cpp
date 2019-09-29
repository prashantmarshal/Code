#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node() {}

    Node(int _val, Node* _next, Node* _random) {
        val = _val;
        next = _next;
        random = _random;
    }
};

class Solution {
public:
    Node* copyRandomList(Node* head) {
        ///Using method without extra space

        // 1. Inserting in between
        Node *curr = head, *head_clone = NULL, *curr_clone = NULL;

        while(curr) {
            curr_clone = new Node(curr->val, NULL, NULL);

            if(!head_clone)
                head_clone = curr_clone;

            curr_clone->next = curr->next;
            curr->next = curr_clone;
            curr = curr_clone->next;
        }

        curr = head;
        curr_clone = head_clone;

        // 2. Fix random pointers
        while(curr){
            if(curr->random){
                curr_clone->random = curr->random->next;            
            } else {
                curr_clone->random = NULL;
            }

            curr = curr_clone->next;
            if(!curr)
                break;

            curr_clone = curr->next;
        }

        curr = head;
        curr_clone = head_clone;

        // 3. Split original and copy
        while(curr){
            curr->next = curr_clone->next;
            curr = curr->next;

            if(!curr)
                break;

            curr_clone->next = curr->next;
            curr_clone = curr_clone->next;
        }

        return head_clone;
    }
};