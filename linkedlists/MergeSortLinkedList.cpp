#include <bits/stdc++.h>
using namespace std;

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

	ListNode *merge(ListNode *head1, ListNode *head2){
		ListNode *dummy = new ListNode(0);
		ListNode *head = dummy;

		while(head1 && head2){
			if(head1->val <= head2->val){
				dummy->next = head1;
				head1 = head1->next;
			} else {
				dummy->next = head2;
				head2 = head2->next;
			}
			dummy = dummy->next;
		}

		ListNode *temp = head1 != NULL? head1 : head2;
		while(temp){
			dummy->next = temp;
			temp = temp->next;
			dummy = dummy->next;	
		}

		temp = head->next;
		delete(head);
		return temp;
	}

    ListNode* sortList(ListNode* head) {
        if(!head || !head->next) return head;

        ListNode *slow = head, *fast = head->next;
        while(fast && fast->next) {
        	slow = slow->next;
        	fast = fast->next->next;
        }

        ListNode *head2 = slow->next;
        slow->next = NULL;
        merge(sortList(head), sortList(head2));

        return head;
    }
};