class Solution {
public:
    Node* cloneGraph(Node* node) {
        if (!node) return node;

        map<Node*, Node*> hash_table;
        hash_table[node] = new Node(node->val);

        queue<Node*> queue;
        queue.push(node);

        while (!queue.empty()) {
            Node* temp = queue.front();
            queue.pop();

            for (auto adjacent : temp->neighbors) {
                if (hash_table.find(adjacent) == hash_table.end()) {
                    hash_table[adjacent] = new Node(adjacent->val);
                    queue.push(adjacent);
                }
                hash_table[temp]->neighbors.push_back(hash_table[adjacent]);
            }
        }
        return hash_table[node];
    }
};