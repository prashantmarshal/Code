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
    ListNode* swapPairs(ListNode* head) {
        ListNode *n1, *n2;

        if(head && head->next) {
            n1 = head; n2 = head->next;
            n1->next = n2->next; n2->next = n1;
            head = n2;
            n1->next = swapPairs(n1->next);
        }
        
        return head;
    }
};