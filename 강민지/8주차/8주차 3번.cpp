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

 struct ListHead{
     ListNode* top;
 };

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        
        if(head->next == NULL)  return NULL;

        ListHead* list = new ListHead; 
        list->top = head;

        ListNode* temp = list->top;

        // head 원소 개수 새기
        int count = 1;
        while(temp->next != NULL)
        {
            count++;
            temp = temp->next;
        }
        
        temp = list->top; // temp 초기화

        // 예외 상황
        if(count == n)
            return head->next;

        
        count = count - n;
        for(int i = 0; i < count - 1; i++)
        {
            temp = temp->next;
        }

        if(temp->next->next == NULL)
        {
            temp->next = NULL;
        }
        else
        {
            temp->next = temp->next->next;
        }
        
        return head;
    }
};
