[3주차 4번] / Linked List Cycle/ 7분 / https://leetcode.com/problems/linked-list-cycle/
리스트에 존재하는 무한 사이클이 존재하는지 판별하는 문제

문제 접근
1.  리스트의 head를 리스트의 마지막까지 검사해서, head가 nullptr(사이클 ㄴㄴ)면 return false
2.  사이클 체크는 리스트 각 요소의 주소값을 넣을 수 있는 unordered_set으로 해시 값을 저장
3.  검색해서 같은 주소가 들어가있는걸 확인하면 -> 사이클 존재, return true

개선 사항
1.  현재 방법은 O(n)의 추가 메모리를 사용한다 -> 추가 요구사항인 O(1) 메모리를 사용해서 풀지는 않음
    런타임은 준수하나 메모리 사용이 똥이다
2.  토끼와 거북이 알고리즘(Floyds Tortoise & Hare Algorithm)을 사용하면 O(1)의 메모리로 풀 수 있다고 함
    탐색 속도가 다른 두개의 포인터 slow, fast를 선언하고 -> 두개로 동시에 탐색시키기
    그리고 slow와 fast가 일치하게 되면 -> 사이클이 존재, 만나지 않게 된다면 사이클 존재하지 않는다


// Time taken : 7 m 6 s
//Runtime 11ms
//Beats 66.00 % of users with C++
//Memory 10.60mb
//Beats 11.15 % of users with C++

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

    class Solution {
    public:
        bool hasCycle(ListNode* head) {
            unordered_set<ListNode*> search;

            while (head != nullptr)
            {
                if (search.find(head) == search.end())
                    search.insert(head);
                else
                    return true;

                head = head->next;
            }
            return false;
        }
};
};