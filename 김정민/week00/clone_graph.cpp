// https://leetcode.com/problems/clone-graph/description/

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
    map<int, Node*> NODES;

    Node* cloneGraph(Node* node) {
        if(node == nullptr) return nullptr;
        if(NODES[node->val]) return NODES[node->val];

        Node* newNode = new Node(node->val);
        NODES[newNode->val] = newNode;

        for(auto n: node->neighbors)
        {
            Node* tmp = cloneGraph(n);
            newNode->neighbors.push_back(tmp);
        }

        return newNode;
    }
};