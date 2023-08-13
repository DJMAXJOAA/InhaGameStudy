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
    ListNode* mergeKLists(vector<ListNode*>& lists) 
    {
        //nullptr 지우기
        lists.erase(std::remove_if(lists.begin(),lists.end(), [](auto x) { return x==nullptr; }),lists.end());
        
        //다 지우고 남은게 빈 배열이면 그냥 리턴
        if(lists.empty())
            return nullptr;
        
        std::vector<int> vals;
        ListNode* tempHead = nullptr;
        ListNode* tempRear = nullptr;
        
        bool isLength1 = false;
        for(auto e : lists)
        {
            if(tempRear!=nullptr)
                tempRear->next = e;
            tempHead = e;
            while(tempHead->next != nullptr)
            {
                vals.push_back(tempHead->val);
                tempHead = tempHead->next;
            }
            vals.push_back(tempHead->val);
            tempRear = tempHead;
            
        }
       
        sort(vals.begin(), vals.end());
        
        tempHead = lists.front();
        int idx = 0;
        while(tempHead !=nullptr)
        {
            tempHead->val = vals[idx++];
            tempHead = tempHead->next;
        }
        return lists.front();
    }
};