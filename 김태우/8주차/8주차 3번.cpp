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
    ListNode* removeNthFromEnd(ListNode* head, int n)
    {
        if (head == NULL) return NULL;

        //Use vector to check size
        vector<ListNode*> nodes;

        while (head != NULL)
        {
            nodes.push_back(head);
            head = head->next;
        }

        if (nodes.size() == 1) return NULL;

        int index = nodes.size() - n;

        if (index - 1 >= 0 && index + 1 < nodes.size())
            nodes[index - 1]->next = nodes[index + 1];
        else if (index - 1 < 0)
            nodes[0] = nodes[1];
        else
            nodes[index - 1]->next = NULL;

        return nodes[0];
    }
};

//Use Two Pointers
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* slow = head, * fast = head;
        while (n--) {
            fast = fast->next;
        }

        //erase first(head) node
        if (fast == NULL) {
            return slow->next;

        }

        //find erase interval
        while (fast->next != NULL) {
            slow = slow->next;
            fast = fast->next;
        }

        // change link
        slow->next = slow->next->next;
        return head;
    }



};