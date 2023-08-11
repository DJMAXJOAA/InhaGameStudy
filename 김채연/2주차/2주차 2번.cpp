// Q2. Merge k Sorted Lists
// k ���� ���ĵ� ���� ����Ʈ�� �����Ͽ� �ϳ��� ���ĵ� ����Ʈ�� ����� �����̴�.
// C++ STL�� priority_queue�� �̿��� Ǯ�̸� ����, �켱���� ť�� ������� �����غ���.

// �켱 k ���� ���͸� ��� �켱���� ť�� �����ϰ�
// ListNode ������ cur�� �Űܰ��� ������� �����Ǿ���.

struct Compare
{
    bool operator() (ListNode* a, ListNode* b) {
        return a->val > b->val;
    }
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue< ListNode*, vector<ListNode*>, Compare> pq;

        for (int i = 0; i < lists.size(); i++) { // k ���� ���͸� ��� �켱���� ť�� ����.
            if (lists[i] != NULL)
                pq.push(lists[i]);
        }

        ListNode head(0); //ù��°?
        ListNode* cur = &head;
        while (!pq.empty()) {
            cur->next = pq.top();
            cur = cur->next;

            pq.pop();
            if (cur->next != NULL)
                pq.push(cur->next);
        }

        return head.next;
    }
};