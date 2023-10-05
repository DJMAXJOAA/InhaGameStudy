[10���� 3��] / Reorder List / 1�ð� 3�� / https://leetcode.com/problems/reorder-list/description/

[���� ����]
��� �˰��� = ���Ḯ��Ʈ ��ȸ + ���� :: O(n), O(n)
1. ���ÿ� ��� ��� ������ �־�α�
2. ������ �� ��Ű�鼭 ����Ʈ�� ����
3. ���ݱ��� �ٲ����� ¦��, Ȧ�� �Ǵ� �� ����

[������]
1. �������͸� ����ؼ� �߰� ����(����)�� ������� �ʰ� Ǯ���� �� ����

[�ٸ� Ǯ�� ���]
1. ���Ḯ��Ʈ ��ȸ + �� ������ :: O(n), O(1)

Time taken : 1 hr 3 m 47 s
Runtime 23ms
Beats 94.68 % of users with C++
Memory 19.12MB
Beats 7.47 % of users with C++

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
public:
    void reorderList(ListNode* head)
    {
        if (head == nullptr || head->next == nullptr || head->next->next == nullptr)
            return;

        ListNode* current = head;
        stack<ListNode*> rearNode;

        // ����Ʈ�� ��� ��带 ���ÿ� Ǫ��
        while (current != nullptr)
        {
            rearNode.push(current);
            current = current->next;
        }

        // ���ݺκ��� ����
        current = head;
        int totalNodes = rearNode.size();
        int halfNodes = totalNodes / 2;

        // �ٲٴ� �κ�
        for (int i = 0; i < halfNodes; i++)
        {
            ListNode* next = current->next;
            ListNode* tail = rearNode.top();
            rearNode.pop();

            current->next = tail;
            tail->next = next;

            current = next;
        }

        // ���� ��ȸ ���� (������ ����� next �����ֱ�)
        if (totalNodes % 2 == 0)
        {
            current->next = nullptr;
        }
        else
        {
            current->next->next->next = nullptr;
        }
    }
};

[�ٸ� Ǯ�� ���]
��������(�ΰ��� ���� ����Ʈ�� ������)
1. slow, fast �����͸� ������ ����Ʈ�� ���ݺκб��� ����
2. ����Ʈ�� �� �κ��� �������� ����� ����
3. ������ ������� �ʾƼ� �߰����� ������ ������� ���� O(n)

class Solution {
public:
    void reorderList(ListNode* head) {
        if (!head || !head->next || !head->next->next) return;

        // slow, fast �����ͷ� ����Ʈ�� ���� �κ� ã��
        ListNode* slow = head, * fast = head;
        while (fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // 2. ����Ʈ�� �� �κ����� ������
        ListNode* prev = nullptr, *curr = slow->next, *next = nullptr;
        slow->next = nullptr;
        while (curr) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        // 3. ����Ʈ�� ����
        ListNode* first = head, *second = prev;
        while (second) {
            next = first->next;
            first->next = second;
            second = second->next;
            first->next->next = next;
            first = next;
        }
    }
};