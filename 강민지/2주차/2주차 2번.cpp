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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
       
        vector<int> temp;

        for (int i = 0; i < lists.size(); i++)
        {
            ListNode* root = lists[i];
            while(root != NULL)
            {
                temp.push_back(root->val);
                root = root->next;
            }
        }

        if(temp.empty())    return NULL;

        sort(temp.begin(), temp.end());
        
        int k = 0;
        
        ListNode* root = new ListNode;
        root->val = temp[k++];

        ListNode* answer = root;
        
        while(k != temp.size())
        {
            ListNode* tempNode = new ListNode;
            tempNode->val = temp[k++];
            root->next = tempNode;
            root = tempNode;
        }

        return answer;
    }
};
