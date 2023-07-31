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
    ListNode* reverseList(ListNode* head) 
    {

        ListNode* temp = head; // 맨끝까지 가는 노드
        ListNode* answer = NULL; // 정답

        while(temp != NULL)
        {
            ListNode* a = temp->next;
            temp->next = answer;
            answer = temp;
            temp = a;
        }

        return answer;
    }
};
