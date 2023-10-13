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

       vector<int> temp;

       ListNode *ptr1 = head;
       ListNode *ptr2 = head;

        while(ptr1 != NULL)
        {
            temp.push_back(ptr1->val);
            ptr1 = ptr1->next;
        }

        int left = 0;
        int right = temp.size() -1;
        bool flag = true;

        while(ptr2 != NULL && left <= right)
        {
            if(flag)
                ptr2->val = temp[left++];
            else
                ptr2->val = temp[right--];

            ptr2 = ptr2->next;
            
            flag = !flag;
        }

        return;
    }
};
