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
class Solution {
public:
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        //구조가 같고, 값이 다 같으면 True
        //root을 bfs로 순회하면서 subRoot의 val과 root->val이 같다면 탐색 시작
        //탐색은 dfs로
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty())
        {
            TreeNode* node = q.front();
            q.pop();
            if(node->val == subRoot->val)
            {
                if(dfs(node, subRoot))
                    return true;
            }
            if(node->left!=nullptr)
                q.push(node->left);
            if(node->right!=nullptr)
                q.push(node->right);

        }
        return false;
    }
    bool dfs(TreeNode* root, TreeNode* subRoot)
    {
        //구조가 맞는지
        if((root==nullptr && subRoot!=nullptr) || (root!=nullptr&&subRoot==nullptr))
            return false;
        else if(root == nullptr && subRoot == nullptr)
            return true;
        else if(root->val != subRoot->val)
            return false;
        else 
            return dfs(root->left, subRoot->left) && dfs(root->right, subRoot->right);
    }
};