/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:
    int INF = -9999;
    vector<int> V;

    void traverse(TreeNode* root) {
        if(root == nullptr)
        {
            V.push_back(INF);
            return;
        }

        V.push_back(root->val);
        traverse(root->left);
        traverse(root->right);
    }

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        V.clear();
        traverse(root);
        string ret = "";
        for(int i=0; i<V.size(); i++) {
            ret += to_string(V[i]);
            ret += ',';
        }

        return ret;
    }

    vector<int> dV;
    int idx = -1;
    TreeNode* makeTree() {
        int cur = dV[idx++];
        if(cur == INF) return nullptr;

        TreeNode* node = new TreeNode(cur);
        node->left = makeTree();
        node->right = makeTree();

        return node;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        dV.clear();
        idx = 0;
        string tmp = "";
        for(int i=0; i<data.size(); i++) {
            if(data[i] == ',') {
                dV.push_back(stoi(tmp));
                tmp = "";
                continue;
            }
            tmp += data[i];
        }

        return makeTree();
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));