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
        ListNode *n1, *n2, *prev = nullptr, **curr = &head;

        while (*curr && (*curr)->next) {
            n1 = *curr; n2 = (*curr)->next;
            n1->next = n2->next; n2->next = n1;
            if (prev) {
                prev->next = n2;
            }
            prev = n1;
            *curr = n2;
            curr = &(n1->next);
        }

        return head;
    }
};