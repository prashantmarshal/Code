// https://leetcode.com/problems/rotate-list/
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
    ListNode* rotateRight(ListNode* head, int k) {
        if (head == nullptr) return nullptr;

        int len = 0;
        ListNode *curr = head, *end = nullptr, *tail = nullptr;
        while(curr) {
            len++; 
            tail = curr;
            curr = curr->next;
        }

        k = k%len; if (k == 0) return head;
        len = len-k; // length to rotate
        curr = head;
        while(curr && len-- > 0) {
            end = curr;
            curr = curr->next;
        }
        end->next = nullptr; // end cannot be null because end is one step behind curr
        // if (curr == nullptr) return head; // not required after (k == 0) condition

        tail->next = head;
        head = curr;
        
        return head;
    }
};