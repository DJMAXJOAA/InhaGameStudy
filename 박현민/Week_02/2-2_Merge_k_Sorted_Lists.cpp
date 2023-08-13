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
    struct compare
    {
        bool operator()(ListNode* a, ListNode* b)
        {
            return a->val > b->val;
        }
    };
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, compare> pq;

        int size = lists.size();
        for (int i = 0; i < size; i++)
        {
            if (lists[i] != NULL)
                pq.push(lists[i]);
        }

        if (pq.empty())
            return NULL;

        ListNode* head = new ListNode();
        ListNode* last = head;

        while (!pq.empty())
        {
            ListNode* curr = pq.top();
            pq.pop();

            last->next = curr;
            last = last->next;

            if (curr->next != NULL)
                pq.push(curr->next);
        }

        return head->next;
    }
};