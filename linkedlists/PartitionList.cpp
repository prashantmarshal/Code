/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode *a = new ListNode(), *a2 = a, *b = new ListNode(), *b2 = b;
        ListNode *curr = head;

        while(curr) {
            if(curr->val < x) {
                a->next = curr;
                a = a->next;
            } else {
                b->next = curr;
                b = b->next;
            }
            curr = curr->next;
        }
        b->next = NULL;
        a->next = b2->next;
        head = a2->next;
        delete(a2); delete(b2);
        return head;
    }
};