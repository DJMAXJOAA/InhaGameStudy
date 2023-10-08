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
    void reorderList(ListNode* head)
    {
        vector<ListNode*> Node;
        vector<ListNode*> revNode;

        while (head != NULL)
        {
            Node.push_back(head);
            head = head->next;
        }

        int num = Node.size();

        for (int i = 0; i < num / 2; i++)
        {
            revNode.push_back(Node.back());
            Node.pop_back();
        }

        if (num % 2)
        {
            for (int i = 0; i < num / 2; i++)
            {
                Node[i]->next = revNode[i];
            }

            for (int i = 0; i < num / 2; i++)
            {
                revNode[i]->next = Node[i + 1];
            }

            Node.back()->next = NULL;
        }

        else
        {
            for (int i = 0; i < num / 2; i++)
            {
                Node[i]->next = revNode[i];
            }

            for (int i = 0; i < num / 2 - 1; i++)
            {
                revNode[i]->next = Node[i + 1];
            }

            revNode.back()->next = NULL;
        }


    }
};
// class Solution {
// public:
//     void reorderList(ListNode* head) 
//     {
//         vector<ListNode*> Nodes;
//         while(head !=NULL)
//         {
//             Nodes.push_back(head);
//             head=head->next;
//         }

//         int n = Nodes.size() - 1;
//         for(int i = 0; i < Nodes.size(); i++)
//         {
//             Nodes[i]->next = Nodes[n];
//             Nodes[n]->next = Nodes[i+1];
//             n--;
//             if(n == i+1) break;
//             if(n == i+2) break;
//         }

//         Nodes[n]->next = NULL;
//     }
// };