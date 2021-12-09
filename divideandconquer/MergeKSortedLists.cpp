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

    ListNode* merge2ListsRecursive(ListNode *a, ListNode *b) {
        if(a == nullptr) return b;
        else if(b == nullptr) return a;

        if(a->val <= b->val) {
            a->next = merge2ListsRecursive(a->next, b); return a;
        } else {
            b->next = merge2ListsRecursive(a, b->next); return b;
        }
    }

    ListNode* merge2Lists(ListNode* a, ListNode* b) {
        ListNode* head = new ListNode(), *head_orig = head;
        while(a && b) {
            if(a->val <= b->val) {
                head->next = a; a = a->next;
            } else {
                head->next = b; b = b->next;
            }
            head = head->next;
        }
        
        if(a) head->next = a;
        else  head->next = b;

        head = head_orig->next;
        delete(head_orig);
        return head;
    }

    /* ListNode* mergeKListsDnQ(vector<ListNode*> &lists) {
        if(lists.empty()) return nullptr;

        while(lists.size() > 1) {
            lists.push_back(merge2ListsRecursive(lists[0], lists[1]));
            lists.erase(lists.begin());
            lists.erase(lists.begin());
        }

        return lists.front();
    } */

    ListNode* mergeKListsDnQ(vector<ListNode*> &lists) {
        if(lists.empty()) return nullptr;

        int index = 0; int size = lists.size();
        while(size > 1) {
            index = 0;
            for (int i = 0; i < size;) {
                if(i+1 == size) {
                    lists[index++] = lists[i++];
                } else {
                    lists[index++] = merge2ListsRecursive(lists[i++], lists[i++]);
                }
            }
            size = index;
        }
        return lists[0];
    }


    ListNode* mergeKLists(vector<ListNode*>& lists) {
        return mergeKListsDnQ(lists);
    }
};