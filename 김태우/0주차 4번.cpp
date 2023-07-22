class Solution
{
public:

    Node* cloneGraph(Node* node)
    {
        if (node == NULL) return NULL;
        queue<Node*> n;

        int visited[101] = { 0 };
        visited[node->val] = 1;
        Node* rootNode = new Node;
        rootNode->val = node->val;
        n.push(node);

        map<Node*, Node*> mp;
        mp[node] = rootNode;

        while (!n.empty())
        {
            Node* cur = n.front();
            n.pop();

            for (auto i : cur->neighbors)
            {
                if (visited[i->val] == 0)
                {
                    Node* temp = new Node;
                    temp->val = i->val;
                    visited[i->val] = 1;
                    mp[i] = temp;
                    n.push(i);
                }

                mp[cur]->neighbors.push_back(mp[i]);
            }

        }

        return mp[node];
    }
};