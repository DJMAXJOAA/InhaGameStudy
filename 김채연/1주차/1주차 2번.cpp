class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if (!head) return head;

        ListNode* curr = head;
        ListNode* prev = NULL; //마지막 노드의 next는 null이니까.
        while (head) {//헤드가 있을때까지. =스왑
            curr = head->next;
            head->next = prev;
            prev = head;
            head = curr;
        }
        return prev;
    }
};