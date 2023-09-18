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

/*
    Two Pointers
    Runtime: 3 ms (72.60%)
    Memory: 11.00 MB (7.72%)
*/

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (head == NULL)
            return NULL;

        ListNode* firstPointer = head;
        ListNode* secondPointer = head;

        for (int i = 1; i <= n; i++)
            firstPointer = firstPointer->next;

        if (firstPointer == NULL)
        {
            ListNode* temp = head->next;
            head->next = NULL;
            delete(head);
            return temp;
        }

        while (firstPointer->next)
        {
            firstPointer = firstPointer->next;
            secondPointer = secondPointer->next;
        }

        ListNode* temp = secondPointer->next;
        secondPointer->next = temp->next;
        delete(temp);
        return head;
    }
};

/*
    Double Scan
    Runtime: 3 ms (72.60%)
    Memory: 11.00 MB (7.72%)
*/

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (head == NULL)
            return NULL;

        int length = 0;
        ListNode* temp = head;

        while (temp != NULL)
        {
            length = length + 1;
            temp = temp->next;
        }

        length = length - n;

        if (length == 0)
        {
            temp = head->next;
            head->next = NULL;
            delete(head);
            return temp;
        }

        ListNode* curr = head;
        ListNode* prev = NULL;

        while (length > 0)
        {
            prev = curr;
            curr = curr->next;
            length = length - 1;
        }

        prev->next = curr->next;
        curr->next = NULL;
        delete(curr);
        return head;
    }
};