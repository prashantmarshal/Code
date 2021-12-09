class Solution {
public:
    ListNode* swapNodes(ListNode* head, int k) {
        // Swap the values
        ListNode *curr, *n1, *n2;
        curr = n1 = n2 = nullptr;

        int n = k-1;
        for(curr = head; curr != NULL; curr = curr->next) {
            n2 = n2 == nullptr ? nullptr : n2->next;
            if (n-- == 0) { // k-1 loops done
                n1 = curr;
                n2 = head;
            }
        }

        if (n >= 0) return head; // linked list is smaller than n nodes

        swap(n1->val, n2->val);
        return head;
    }
};