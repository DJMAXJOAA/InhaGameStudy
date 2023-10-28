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

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        //dfs로 탐색하면서 다 더하기
        string s = "";
        if(nullptr == root)
        {
            s += "#,";
            return s;
        }
        s+=to_string(root->val);
        s+=",";
        s+=serialize(root->left);
        s+=serialize(root->right);
        return s;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        //bfs로 찾아가면서 값 넣어주기
        queue<int> q;
        istringstream ss(data);
        string token;
        while(getline(ss, token, ','))
        {
            if(token == "#")
                q.push(-9999);
            else
            {
                int num = stoi(token);
                q.push(num);
            }
        }
        
        return buildTree(q);
    }
    TreeNode* buildTree(queue<int>& q)
    {
        if(q.empty())
            return nullptr;
        
        int val = q.front();
        q.pop();
        if(val == -9999)
            return nullptr;
        
        TreeNode* node = new TreeNode(val);
        node->left = buildTree(q);
        node->right = buildTree(q);
        return node;
    }
    
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));