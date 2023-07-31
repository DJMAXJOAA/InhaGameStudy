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
    ListNode* reverseList(ListNode* head) {
        ListNode* parent = nullptr;

        while (head != nullptr)
        {
            ListNode* curr = head;
            head = head->next;
            curr->next = parent;
            parent = curr;
        }

        return parent;
    }
};