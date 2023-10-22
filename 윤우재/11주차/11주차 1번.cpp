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
    int curDepth = -1;
    int maxDepth = -1;
    vector<vector<int>> answer;
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(nullptr == root) return answer;
        curDepth++;
        if(curDepth>maxDepth)
        {
            maxDepth = curDepth;
            vector<int> temp;
            answer.push_back(temp);
        }
        answer[curDepth].push_back(root->val);
        levelOrder(root->left);
        levelOrder(root->right);
        curDepth--;
        return answer;
    }
};