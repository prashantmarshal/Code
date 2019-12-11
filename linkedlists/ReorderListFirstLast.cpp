// https://leetcode.com/problems/reorder-list/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
	int reorderUtil(ListNode **head, ListNode *curr) {
		if(!curr) return 0;
        
		int ret = reorderUtil(head, curr->next);
        if (ret) return 1;
		
        if(*head == curr || (*head)->next == curr) {
            curr->next = NULL;
            return 1;
        }
        
        ListNode *temp = (*head)->next;
		(*head)->next = curr;
        curr->next = temp;
        *head = temp;

		return 0;
	}

	void reorderList(ListNode* head) {
		if(!head || !head->next || !head->next->next) return;
		ListNode **start = &head;
		reorderUtil(start, head);
	}
};