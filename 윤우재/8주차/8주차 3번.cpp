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

        //1. 한 번 순회하면서 스택에 메모리를 다 넣음
        //2. 순회 다 했으면 n만큼 pop
        //3. stack.back() 참조하면 뽑아내야 할 노드의 직전 노드가 나옴
        //3-1. stack.empty()라면 맨 처음걸 뽑는 상황이므로 return head->next;
        //4. 참조한 노드의 next를 next->next에 이어준다
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