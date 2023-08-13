// https://leetcode.com/problems/linked-list-cycle/

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
    bool hasCycle(ListNode *head) {
        if(head == nullptr) return false;

        ListNode* h1 = head;
        ListNode* h2 = head->next;

        while(1)
        {
            if(h1 == nullptr || h2 == nullptr) break;
            if(h1 == h2) return true;

            h1 = h1->next;

            if(h2->next)
            {
                h2 = h2->next->next;
            }
            else break;
        }

        return false;
    }
};