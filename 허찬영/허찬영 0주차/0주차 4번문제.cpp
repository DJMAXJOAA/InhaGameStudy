// Definition for a Node
/*
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    vector<Node*> allNodes;
    vector<Node*> originNodes;
    void DFS(Node *node, Node *newnode)
    {
        int check;
        Node *temp;
        Node *checktemp;
        for(int i = 0; i < node->neighbors.size(); i++)
        {
            temp = node->neighbors[i];
            check = 0;
            for(int j = 0; j < allNodes.size(); j++)
            {
                if(allNodes[j]->val == temp->val)
                {
                    check = 1;
                    checktemp = allNodes[j];
                    break;
                }
            }

            if(check == 0)
            {
                Node* createnode = new Node;
                createnode->val = temp->val;
                newnode->neighbors.push_back(createnode);
                allNodes.push_back(createnode);
                originNodes.push_back(temp);
            }
            else
                newnode->neighbors.push_back(checktemp);
        }
    }
    Node* cloneGraph(Node* node) 
    {
        if(node == nullptr)
            return nullptr;
        Node *ans = new Node;
        ans->val = node->val;
        allNodes.push_back(ans);
        originNodes.push_back(node);
        for(int i = 0; i < allNodes.size(); i++)
            DFS(originNodes[i], allNodes[i]);

        return ans;
    }
};
