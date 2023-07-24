/*
// Definition for a Node.
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
    Node* cloneGraph(Node* node) {
        if (node == nullptr)
            return nullptr;

        Node* root = new Node(1);

        if (!node->neighbors.empty())
        {
            vector<Node*> nodeList(100);
            vector<bool> isVisit(100, false);
            nodeList[0] = root;
            for (int i = 1; i < 100; i++)
            {
                nodeList[i] = new Node(i + 1);
            }

            Node* base = node;
            Node* copy = root;

            DFS(copy, base, nodeList, isVisit);
        }

        return root;
    }

    void DFS(Node* copy, Node* base, vector<Node*>& nodeList, vector<bool>& isVisit)
    {
        isVisit[copy->val - 1] = true;

        for (int i = 0; i < base->neighbors.size(); i++)
        {
            copy->neighbors.push_back(nodeList[base->neighbors[i]->val - 1]);
        }

        for (int j = 0; j < copy->neighbors.size(); j++)
        {
            if (!isVisit[copy->neighbors[j]->val - 1])
            {
                DFS(copy->neighbors[j], base->neighbors[j], nodeList, isVisit);
            }
        }
    }
};