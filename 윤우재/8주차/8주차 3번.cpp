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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (head->next == nullptr)return nullptr;

        //1. �� �� ��ȸ�ϸ鼭 ���ÿ� �޸𸮸� �� ����
        //2. ��ȸ �� ������ n��ŭ pop
        //3. stack.back() �����ϸ� �̾Ƴ��� �� ����� ���� ��尡 ����
        //3-1. stack.empty()��� �� ó���� �̴� ��Ȳ�̹Ƿ� return head->next;
        //4. ������ ����� next�� next->next�� �̾��ش�
        vector<ListNode*> stack;
        ListNode* cur = head;
        while (nullptr != cur)
        {
            stack.push_back(cur);
            cur = cur->next;
        }
        for (int i = 0; i < n; i++)
            stack.pop_back();

        if (stack.empty()) return head->next;

        cur = stack.back();
        cur->next = cur->next->next;
        return head;
    }
};