/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
    //bool passed[200001];
    vector<ListNode*> passed;
public:
    // bool hasCycle(ListNode *head) 
    // {
    //     bool ans=false;
    //     while(head !=NULL)
    //     {
    //         if(passed[head->val + 100000]==true)
    //         {
    //             ans = true;
    //             break;
    //         }
    //         passed[head->val + 100000]=true;
    //         head=head->next;
    //     }

    //     return ans;
    // }

    bool hasCycle(ListNode* head)
    {
        //I only think about value issue...

        ListNode* slow = head;
        ListNode* fast = head;

        while (fast != NULL && fast->next != NULL)
        {
            fast = fast->next->next;
            slow = slow->next;
            if (slow == fast) return true;
        }

        return false;
    }

    // bool hasCycle(ListNode *head) //TIME LIMIT
    // {   
    //     bool ans = false;
    //     while(head !=NULL)
    //     {
    //         int i;
    //         for(i = 0; i < passed.size();i++)
    //         {
    //             if(passed[i] == head)
    //             {
    //                 ans = true;
    //                 break;
    //             }
    //         }

    //         if(!passed.empty())
    //         {
    //             if(passed[i] !=head)
    //             {
    //                 ListNode * temp = head;
    //                 passed.push_back(temp);
    //                 head=head->next;
    //             }
    //         else
    //             break;
    //         }
    //     }
    //     return ans;
    // }
};