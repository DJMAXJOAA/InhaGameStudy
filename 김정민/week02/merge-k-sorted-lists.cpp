// https://leetcode.com/problems/merge-k-sorted-lists/

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
    ListNode* mergeTwo(ListNode* list1, ListNode* list2)
    {
        if(list1 == nullptr && list2 == nullptr) return nullptr;
        if(list1 == nullptr) return list2;
        if(list2 == nullptr) return list1;

        if(list1->val < list2->val)
        {
            list1->next = mergeTwo(list1->next, list2);
            return list1;
        }
        else
        {
            list2->next = mergeTwo(list1, list2->next);
            return list2;
        }
    }

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.empty()) return nullptr;
        ListNode* head = lists[0];

        int idx = 1;
        while(idx < lists.size())
        {
            head = mergeTwo(head, lists[idx++]);
        }

        return head;
    }
};