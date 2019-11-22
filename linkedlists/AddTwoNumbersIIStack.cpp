/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

ListNode* reverseList(ListNode *head, ListNode **res) {
	if(!head) return NULL;

	ListNode *temp = reverseList(head->next, res);
	if(temp) {
		if(*res == NULL)
			*res = temp;
		temp->next = head;
	}

	return head;
}

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    	stack<int>s1, s2;
    	ListNode *t = l1;
    	while(t){
    		s1.push(t->val);
    		t = t->next;
    	}

    	if(s1.empty()) return l2;

    	t = l2;
    	while(t){
    		s2.push(t->val);
    		t = t->next;
    	}

		if(s2.empty()) return l1;
    	
    	ListNode *dummy = new ListNode(0);
    	ListNode *head = dummy;

    	int carry = 0;
		while(!s1.empty() && !s2.empty()){
			int sum = s1.top() + s2.top() + carry;
			carry = sum/10;
			sum = sum%10;
			head->next = new ListNode(sum);
			head = head->next;
			s1.pop();
			s2.pop();
		}

		while(!s1.empty()){
			int sum = s1.top() + carry;
			s1.pop();
			carry = sum/10;
			sum = sum%10;
			head->next = new ListNode(sum);
			head = head->next;
		}		


		while(!s2.empty()){
			int sum = s2.top() + carry;
			s2.pop();
			carry = sum/10;
			sum = sum%10;
			head->next = new ListNode(sum);
			head = head->next;
		}		

		ListNode *res = NULL;
		reverseList(dummy->next, &res);
		return res;
	}
};


