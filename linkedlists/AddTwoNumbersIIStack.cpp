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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        stack<int> s1, s2;
        ListNode *c1 = l1, *c2 = l2;
        while(c1 || c2) {
            if(c1) s1.push(c1->val);
            if(c2) s2.push(c2->val);
            c1 = c1 ? c1->next : nullptr;
            c2 = c2 ? c2->next : nullptr;
        }

        ListNode *res = new ListNode();
        ListNode *ret = res;
        stack<int> result;

        int sum = 0, carry = 0;
        while(!s1.empty() || !s2.empty() || carry) {
            sum = (!s1.empty() ? s1.top() : 0) + (!s2.empty() ? s2.top() : 0) + carry;
            carry = sum / 10;
            sum = sum%10;
            result.push(sum);
            if(!s1.empty()) s1.pop(); if(!s2.empty()) s2.pop();
        }

        while(!result.empty()) {
            res->next = new ListNode(result.top());
            result.pop();
            res = res->next;
        }

        return ret->next;
    }
};