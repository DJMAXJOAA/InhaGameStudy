//Q4.Linked List Cycle
//cycle�� �ִ� linked list���� ���� ����.
// 
// 
//fast�� slow��� �����͸� �����Ͽ�, fast�� 2���� �̵�, slow�� 1���� �̵�
//fast�� slow�� ������ true
//
//-> ��� head�� ��츦 �˻��� �� �ְ�, ������ ������� �˻�����.

class Solution {
public:
	bool hasCycle(ListNode* head) {
		ListNode* slow = head;
		ListNode* fast = head;

		while (fast && fast->next) // fast�� 2���� �����̴ϱ� fast��next�ִ���
		{
			slow = slow->next;
			fast = fast->next->next;

			if (slow == fast)
				return true;
		}

		return false;
	}
};