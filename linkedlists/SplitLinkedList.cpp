// https://leetcode.com/problems/split-linked-list-in-parts/

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
    vector<ListNode*> splitListToParts(ListNode* root, int k) {

        vector<ListNode*> res;
        ListNode* curr = root, *head = root, *end = nullptr; // end denotes the last node of a part

        int len = 0;
        while (curr) {
            len++; curr = curr->next;
        }

        int size = len/k; 
        int remaining = len % k;
        curr = head;

        while (curr) {
            size = len/k; // reset size
            while(curr && size--) {
                end = curr; // end points one node behind curr
                curr = curr->next;
            }

            if (remaining-- > 0) {
                end = curr;
                curr = curr->next;
            }
            end->next = nullptr;

            res.push_back(head);
            head = curr;
        }

        while (res.size() != k) {
            res.push_back(nullptr);
        }
        return res;
    }
};