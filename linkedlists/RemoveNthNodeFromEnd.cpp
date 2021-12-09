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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *slow = head, *fast = head;
        ListNode *prev = new ListNode(0), *prev_copy = prev; 
        
        int k = n;
        while(k-- > 0) {
            if(!fast)
                break;
            fast = fast->next;
        }

        if(k > 0) return head;

        while(fast) {
            prev = slow;
            slow = slow->next;
            fast = fast->next;
        }

        prev->next = slow->next
        if (slow == head) {
            head = slow->next;
        }

        delete(slow);
        delete(prev_copy);
        return head;
    }
};