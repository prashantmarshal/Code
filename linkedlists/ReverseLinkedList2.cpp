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

    ListNode *reverseUtil(ListNode *a, ListNode *b) {

        if(a == b) {
            return b;
        }

        ListNode *tmp = reverseUtil(a->next, b);
        if (tmp) {
            tmp->next = a;
            a->next = nullptr;
        }

        return a;
    }


    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode *l1 = nullptr, *l2 = nullptr;
        ListNode *r1 = nullptr, *r2 = nullptr;

        ListNode *curr = head;

        int i = 1;
        while (curr) {
            if(i++ == left) {
                l2 = curr;
                curr = curr->next;

                while (curr) {
                    if(i++ == right) {
                        r2 = curr;
                        r1 = curr->next;
                        curr = curr->next;
                        break;
                    }
                    curr = curr->next;
                }
                break;
            }
            l1 = curr;
            curr = curr->next;
        }

        if (l2 && r2) {
            reverseUtil(l2, r2);
        }

        if(l2) {
            l2->next = r1;
        }

        if(l1) {
            l1->next = r2;
        }
        
        return head;
    }
};