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

    void util(ListNode **head, ListNode *first, ListNode *second) {
        if (second == nullptr) {
            *head = first;
            return;
        }

        ListNode *new_second = second->next;
        second->next = first;
        util(head, second, new_second);
    }

    ListNode* reverseList(ListNode* head) {
        if (head == nullptr) return nullptr;
        util(&head, NULL, head);
        return head;
    }

    ListNode* reverseList(ListNode* head) {
        if(head == nullptr) return nullptr;

        ListNode *prev = NULL, *curr = head, *next = head->next;
        while(curr) {
            curr->next = prev;
            prev = curr;
            curr = next;
            if(next) {
                next = next->next;
            }
        }

        return prev;
    }
};