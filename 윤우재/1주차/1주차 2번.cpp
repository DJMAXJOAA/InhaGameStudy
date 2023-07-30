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
        if(head==nullptr)
            return nullptr;
        
        vector<ListNode*> NodePtrVec;
        while(head->next != nullptr)
        {
            NodePtrVec.push_back(head);
            head = head->next;
        }
        //NodePtrVec.pop_back();
        ListNode* temp = head;
        
        for(int i = NodePtrVec.size()-1;i>=0;i--)
        {
            temp->next = NodePtrVec[i];
            temp = temp->next;
        }
        temp->next = nullptr;

        return head;
    }
};