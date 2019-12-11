// https://leetcode.com/problems/reorder-list/

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
    void reorderList(ListNode* head) {
        stack<ListNode*> s;

        ListNode *start = head;
        while(start){
        	s.push(start);
        	start = start->next;
        }

        start = head;

        while(true) {
        	if(start == s.top() || start->next == s.top()) {
        		break;
        	}

        	ListNode *tmp = start->next;
        	start->next = s.top();
        	s.top()->next = tmp;
        	s.pop();
        	start = tmp;
        }
    }
};