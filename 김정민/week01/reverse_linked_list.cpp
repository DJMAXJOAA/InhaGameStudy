// https://leetcode.com/problems/reverse-linked-list/

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
    // recursive solution
    ListNode* reverse(ListNode* head)
    {
        if(head == nullptr) return nullptr;
        if(head->next == nullptr) return head;

        ListNode* tmp = reverse(head->next);
        head->next->next = head;
        head->next = nullptr;

        return tmp;
    }

    ListNode* reverseList(ListNode* head) {
        // iteratively solution
        // if(head == nullptr) return nullptr;

        // ListNode* prv = nullptr;
        // while(head)
        // {
        //     ListNode* tmp = head;
        //     head = head->next;
        //     tmp->next = prv;
        //     prv = tmp;
        // }

        // return prv;

        return reverse(head);
    }
};
