// �־��� ��ũ�� ����Ʈ���� ������ n��° ��带 �����ϰ� �� head�� ��ȯ�ض�.n�� ������ ��ȿ�� ����.

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

        if (total == n) { //�� ó�� ��� ����.
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