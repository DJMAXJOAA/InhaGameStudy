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
        if(nullptr==head)return false;
        vector<ListNode*> temp;
        ListNode* cur = head;
        while(nullptr!=cur->next)
        {
            if(check(temp, cur)) return true;
            temp.push_back(cur);
            cur = cur->next;
        }
        return false;
    }
    bool check(vector<ListNode*>& v, ListNode* pNode)
    {
        for(auto e : v)
            if(pNode == e) return true;
        
        return false;
    }
};