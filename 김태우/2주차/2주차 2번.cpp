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
    static bool compare(pair<int, ListNode*> a, pair<int, ListNode*> b)
    {
        return a.first < b.first; //if sign is opposite, descending order
    }

    ListNode* mergeKLists(vector<ListNode*>& lists)
    {
        int k = lists.size();
        if (k == 0) return NULL; //if no Node, return

        vector<pair<int, ListNode*>> p;

        for (int i = 0; i < k; i++) //put all variables int to pair
        {
            ListNode* list = lists[i];

            while (list != NULL)
            {
                p.push_back({ list->val,list });
                list = list->next;
            }
        }

        if (p.size() == 0) return NULL;

        sort(p.begin(), p.end(), compare); //sorting acsending order

        for (int i = 0; i < p.size() - 1; i++) //linked
        {
            p[i].second->next = p[i + 1].second;
        }

        p[p.size() - 1].second->next = NULL; //last is NULL

        return p[0].second;

    }
};