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
    bool hasCycle(ListNode* head) {
        if (head == NULL)
            return false;
        map<ListNode*, bool> isVisit;
        while (head->next != nullptr)
        {
            if (isVisit.insert(make_pair(head->next, true)).second == false)
                return true;
            head = head->next;
        }
        return false;
    }
};