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
    void reorderList(ListNode* head) {
        int n = 0;
        ListNode* rear = head;
        while(rear) {
            rear = rear->next;
            n++;
        }

        if(n == 1)
            return;

        rear = head;
        int half = n/2;
        while(half--) {
            rear = rear->next;
        }

        ListNode* prv = nullptr;
        while(rear) {
            ListNode* tmp = rear;
            ListNode* nxt = rear->next;
            rear->next = prv;
            rear = nxt;
            prv = tmp;
        }

        // while(prv) {
        //     cout << prv->val << ' ';
        //     prv = prv->next;
        // }
        // cout << endl;

        ListNode* h = head;
        bool flag = true;
        half = n - 1;
        while(half--) {
            if(flag) {
                ListNode* tmp = h->next;
                h->next = prv;
                h = tmp;
                flag = false;
            }
            else {
                ListNode* tmp = prv->next;
                prv->next = h;
                prv = tmp;
                flag = true;
            }
        }
    }
};