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

        ListNode* prev = nullptr;
        ListNode* current = head; // 임시 노드
        while (current != nullptr)
        {
            ListNode* temp = current->next; // 임시 저장
            current->next = prev;
            prev = current;
            current = temp; // current->next랑 같음
        }

        return prev;
    }
};