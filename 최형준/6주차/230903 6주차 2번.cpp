[6주차 2번] / Merge Two Sorted Lists / 13분 / https://leetcode.com/problems/merge-two-sorted-lists/

[문제 접근]
사용 알고리즘 :: 우선순위 큐
1.	우선순위 큐에 list1, list2의 값을 오름차순 정렬
2.	새로운 ListNode*에 동적할당해서 반환

[개선점]
1.	이미 리스트가 정렬되어 있으니까, 우선순위 큐를 새로 선언할 필요는 없음(추가 메모리 필요)
2.	새로 공간을 할당하는 것이 아니라, 주어졌던 리스트 공간만 이용 가능 (In-place Algorithm)

[다른 풀이 방법]
1. 투 포인터(Two Pointer) + 제자리 알고리즘(In - place Algorithm)

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

[다른 풀이 방법]
1. 투 포인터(Two Pointer) + 제자리 알고리즘(In - place Algorithm)

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

        // 두 리스트가 nullptr이 아니어야 함
        while (list1 && list2)
        {
            // 두 리스트를 비교하고, result에 주소를 추가
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

        // 만약 두 리스트 중에 남아있는 리스트가 있으면, 
        // 그대로 current의 next에 추가만 해주면 두 리스트가 이어지게 됨
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