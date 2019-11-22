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

int findLength(ListNode *head) {
	int len = 0;
	while(head) {
		len++;
		head = head->next;
	}
	return len;
}

ListNode *addTwoLists(ListNode *head1, ListNode *head2, int &carry) {
	if(head1) {
		ListNode *temp = new ListNode(0);
		temp->next = addTwoLists(head1->next, head2->next, carry);

		int sum = head1->val + head2->val + carry;
		temp->val = sum%10;
		carry = sum/10;

		return temp;
	}

	return NULL;
}

ListNode *addNumber(ListNode *head, int number, int diff, int &carry, ListNode *res) {
	if(diff == 0)
		return NULL;

	ListNode *ret, *temp;
	if(diff > 1) {
		ret = addNumber(head->next, number, diff-1, carry, res);
		temp = new ListNode(0);
		int sum = (head->val+carry)%10;
		carry = (head->val+carry)/10;
		temp->val = sum;
        temp->next = ret;
        
		return temp;
	}

	if(diff == 1){
		temp = new ListNode(0);
		int sum = (head->val+number)%10;
		carry = (head->val+number)/10;
		temp->val = sum;
		temp->next = res;

		return temp;
	}

	return NULL;
}

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    	int len1 = findLength(l1);
    	int len2 = findLength(l2);
        
        if(len1 == 0) return l2;
        if(len2 == 0) return l1;
		
		ListNode *head1 = l1, *head2 = l2;
		if(len1 > len2) {
			int diff = len1 - len2;
			while(diff--) head1 = head1->next;
		}    		

		if(len1 < len2) {
			int diff = len2 - len1;
			while(diff--) head2 = head2->next;
		}    		

		int carry = 0;
		ListNode *res = addTwoLists(head1, head2, carry);
		ListNode *ans = res; // If there is extra length
		ListNode *result = res; // If there is extra carry

		if(len1 != len2)
			ans = addNumber(len1 > len2 ? l1 : l2, carry, abs(len1-len2), carry, res);
		
		if(carry) {
			result = new ListNode(carry);
			result->next = ans;
		} else {
            result = ans;
        }
		return result;

    }
};