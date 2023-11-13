/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution
{
    vector<int> temp;
public:
    void Input(TreeNode* node)
    {
        if (node == NULL) return;
        temp.push_back(node->val);
        Input(node->left);
        Input(node->right);
    }

    int kthSmallest(TreeNode* root, int k)
    {
        Input(root);
        sort(temp.begin(), temp.end(), less<int>());
        return temp[k - 1];
    }
};