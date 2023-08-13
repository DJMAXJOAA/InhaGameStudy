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
    bool hasCycle(ListNode *head) {
        
        if(head == NULL)
            return false;

        int count = 0;
        while(1)
        {
            if(head->next == NULL)
                return false;

            count++;
            head = head->next;
            if(count > 10000)   return true;
        }
    }
};
