class Solution {
public:
    int carry = 0;
    void util(ListNode *head) {
        if(!head) {
            carry = 1;
            return;
        }
        
        plusOne(head->next);
        
        int curr = (head->val + carry);
        head->val = curr%10;
        carry = curr/10;
    }

    ListNode * plusOne(ListNode * head) {
        util(head);
        if(carry) {
            ListNode *newHead = new ListNode(1);
            newHead->next = head;
            return newHead;
        }    
        return head;
    }
};