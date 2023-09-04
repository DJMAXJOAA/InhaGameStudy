[6���� 2��] / Merge Two Sorted Lists / 13�� / https://leetcode.com/problems/merge-two-sorted-lists/

[���� ����]
��� �˰��� :: �켱���� ť
1.	�켱���� ť�� list1, list2�� ���� �������� ����
2.	���ο� ListNode*�� �����Ҵ��ؼ� ��ȯ

[������]
1.	�̹� ����Ʈ�� ���ĵǾ� �����ϱ�, �켱���� ť�� ���� ������ �ʿ�� ����(�߰� �޸� �ʿ�)
2.	���� ������ �Ҵ��ϴ� ���� �ƴ϶�, �־����� ����Ʈ ������ �̿� ���� (In-place Algorithm)

[�ٸ� Ǯ�� ���]
1. �� ������(Two Pointer) + ���ڸ� �˰���(In - place Algorithm)

Time taken : 13 m 15 s
Runtime 4ms
Beats 76.68 % of users with C++
Memory 15.19MB
Beats 12.19 % of users with C++

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
		ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
			priority_queue<int, vector<int>, greater<int>> que;
			while (list1)
			{
				que.push(list1->val);
				list1 = list1->next;
			}
			while (list2)
			{
				que.push(list2->val);
				list2 = list2->next;
			}
			if (que.empty())
				return nullptr;

			ListNode* result = new ListNode(que.top());
			que.pop();
			ListNode* temp = result;
			while (!que.empty())
			{
				ListNode* next = new ListNode(que.top());
				que.pop();

				temp->next = next;
				temp = temp->next;
			}
			return result;
		}
};

[�ٸ� Ǯ�� ���]
1. �� ������(Two Pointer) + ���ڸ� �˰���(In - place Algorithm)

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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* result = new ListNode;
        ListNode* current = result;

        // �� ����Ʈ�� nullptr�� �ƴϾ�� ��
        while (list1 && list2)
        {
            // �� ����Ʈ�� ���ϰ�, result�� �ּҸ� �߰�
            if (list1->val < list2->val)
            {
                current->next = list1;
                list1 = list1->next;
            }
            else
            {
                current->next = list2;
                list2 = list2->next;
            }
            current = current->next;
        }

        // ���� �� ����Ʈ �߿� �����ִ� ����Ʈ�� ������, 
        // �״�� current�� next�� �߰��� ���ָ� �� ����Ʈ�� �̾����� ��
        if (list1)
        {
            current->next = list1;
        }
        if (list2)
        {
            current->next = list2;
        }

        return result->next;
    }
};