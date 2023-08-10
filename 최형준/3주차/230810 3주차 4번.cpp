[3���� 4��] / Linked List Cycle/ 7�� / https://leetcode.com/problems/linked-list-cycle/
����Ʈ�� �����ϴ� ���� ����Ŭ�� �����ϴ��� �Ǻ��ϴ� ����

���� ����
1.  ����Ʈ�� head�� ����Ʈ�� ���������� �˻��ؼ�, head�� nullptr(����Ŭ ����)�� return false
2.  ����Ŭ üũ�� ����Ʈ �� ����� �ּҰ��� ���� �� �ִ� unordered_set���� �ؽ� ���� ����
3.  �˻��ؼ� ���� �ּҰ� ���ִ°� Ȯ���ϸ� -> ����Ŭ ����, return true

���� ����
1.  ���� ����� O(n)�� �߰� �޸𸮸� ����Ѵ� -> �߰� �䱸������ O(1) �޸𸮸� ����ؼ� Ǯ���� ����
    ��Ÿ���� �ؼ��ϳ� �޸� ����� ���̴�
2.  �䳢�� �ź��� �˰���(Floyds Tortoise & Hare Algorithm)�� ����ϸ� O(1)�� �޸𸮷� Ǯ �� �ִٰ� ��
    Ž�� �ӵ��� �ٸ� �ΰ��� ������ slow, fast�� �����ϰ� -> �ΰ��� ���ÿ� Ž����Ű��
    �׸��� slow�� fast�� ��ġ�ϰ� �Ǹ� -> ����Ŭ�� ����, ������ �ʰ� �ȴٸ� ����Ŭ �������� �ʴ´�


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