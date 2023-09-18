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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* mover = head;
        ListNode* prv = nullptr;
        ListNode* follower = head;

        for(int i=0; i<n; i++) mover = mover->next;

        while(mover != nullptr)
        {
            mover = mover->next;
            prv = follower;
            follower = follower->next;
        }

        if(!prv)
            head = head->next;
        else
            prv->next = prv->next->next;

        return head;
    }
};
