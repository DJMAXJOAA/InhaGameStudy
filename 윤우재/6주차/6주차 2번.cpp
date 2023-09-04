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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(nullptr == list1 && nullptr == list2)return nullptr;
        if(nullptr == list1)return list2;
        if(nullptr == list2)return list1;

        ListNode* current = (list1->val <= list2->val)? list1 : list2;
        ListNode* other = (current == list1) ? list2 : list1;
        if(nullptr == current->next)
        {
            current->next = other;
            return current;
        }
        ListNode* start = current;
        while(nullptr!=current->next)
        {
            if(other->val >=current->val && other->val <=current->next->val)
            {
                ListNode* temp = other->next;
                other->next = current->next;
                current->next = other;
                other = temp;
            }
            else
            {
                current = current->next;
            }
            if(nullptr==other)break;
        }
        
        if(nullptr!= other && current->val <= other->val)
            current->next = other;
        return start;
    }
};