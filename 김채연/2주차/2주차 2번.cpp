// Q2. Merge k Sorted Lists
// k 개의 정렬된 연결 리스트를 병합하여 하나의 정렬된 리스트로 만드는 문제이다.
// C++ STL의 priority_queue를 이용한 풀이를 통해, 우선순위 큐의 사용방식을 이해해본다.

// 우선 k 개의 벡터를 모두 우선순위 큐에 삽입하고
// ListNode 포인터 cur을 옮겨가는 방식으로 구현되었다.

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

        for (int i = 0; i < lists.size(); i++) { // k 개의 벡터를 모두 우선순위 큐에 삽입.
            if (lists[i] != NULL)
                pq.push(lists[i]);
        }

        ListNode head(0); //첫번째?
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