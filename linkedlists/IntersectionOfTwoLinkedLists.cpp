class Solution {
public:
    int length(ListNode *node) {
        int l = 0;
        while(node) { l++; node = node->next; }
        return l;
    }

    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int a = length(headA), b = length(headB);
        if(a > b) {
            for(int i = 0; i < a-b; i++) headA = headA->next;
        } else for(int i = 0; i < b-a; i++) headB = headB->next;

        while(headA != headB) {
            headA = headA->next; headB = headB->next;
        }

        return headA;
    }
};