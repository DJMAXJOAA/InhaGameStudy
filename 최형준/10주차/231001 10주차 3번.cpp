[10주차 3번] / Reorder List / 1시간 3분 / https://leetcode.com/problems/reorder-list/description/

[문제 접근]
사용 알고리즘 = 연결리스트 순회 + 스택 :: O(n), O(n)
1. 스택에 모든 노드 정보를 넣어두기
2. 스택을 팝 시키면서 리스트를 수정
3. 절반까지 바꿨으면 짝수, 홀수 판단 후 종료

[개선점]
1. 투포인터를 사용해서 추가 공간(스택)을 사용하지 않고 풀이할 수 있음

[다른 풀이 방법]
1. 연결리스트 순회 + 투 포인터 :: O(n), O(1)

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

        // 리스트의 모든 노드를 스택에 푸시
        while (current != nullptr)
        {
            rearNode.push(current);
            current = current->next;
        }

        // 절반부분을 나눔
        current = head;
        int totalNodes = rearNode.size();
        int halfNodes = totalNodes / 2;

        // 바꾸는 부분
        for (int i = 0; i < halfNodes; i++)
        {
            ListNode* next = current->next;
            ListNode* tail = rearNode.top();
            rearNode.pop();

            current->next = tail;
            tail->next = next;

            current = next;
        }

        // 무한 순회 방지 (마지막 노드의 next 지워주기)
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

[다른 풀이 방법]
투포인터(두개의 서브 리스트로 나누기)
1. slow, fast 포인터를 나눠서 리스트를 절반부분까지 나눔
2. 리스트의 뒷 부분을 역순으로 만들고 병합
3. 스택을 사용하지 않아서 추가적인 공간을 사용하지 않음 O(n)

class Solution {
public:
    void reorderList(ListNode* head) {
        if (!head || !head->next || !head->next->next) return;

        // slow, fast 포인터로 리스트의 절반 부분 찾기
        ListNode* slow = head, * fast = head;
        while (fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // 2. 리스트를 두 부분으로 나누기
        ListNode* prev = nullptr, *curr = slow->next, *next = nullptr;
        slow->next = nullptr;
        while (curr) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        // 3. 리스트의 병합
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