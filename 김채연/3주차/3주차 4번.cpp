//Q4.Linked List Cycle
//cycle이 있는 linked list인지 묻는 문제.
// 
// 
//fast와 slow라는 포인터를 선언하여, fast는 2번씩 이동, slow는 1번씩 이동
//fast와 slow가 같으면 true
//
//-> 모든 head의 경우를 검색할 수 있고, 빠르게 다음노드 검색가능.

class Solution {
public:
	bool hasCycle(ListNode* head) {
		ListNode* slow = head;
		ListNode* fast = head;

		while (fast && fast->next) // fast가 2번씩 움직이니까 fast의next있는지
		{
			slow = slow->next;
			fast = fast->next->next;

			if (slow == fast)
				return true;
		}

		return false;
	}
};