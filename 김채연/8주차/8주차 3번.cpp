// 주어진 링크드 리스트에서 끝에서 n번째 노드를 삭제하고 그 head를 반환해라.n은 언제나 유효한 수다.

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        vector<ListNode*> locToNum;

        ListNode* mock = new ListNode(-1);
        mock->next = head;
        ListNode* curr = head;
        int total = 0;

        while (curr) {
            locToNum.push_back(curr);
            total++;
            curr = curr->next;
        }

        if (total == n) { //맨 처음 노드 삭제.
            ListNode* prev = mock;
            prev->next = head->next;
        }
        else {
            ListNode* prev = locToNum[total - n - 1];
            prev->next = locToNum[total - n]->next;
        }

        return mock->next;
    }
};