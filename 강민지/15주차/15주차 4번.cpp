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
private:
    vector<int> answer;
public:
    int DFS(TreeNode* root)
    {
        if(root == NULL) return -1;

        int left = DFS(root->left);
        if(left != -1)
            answer.push_back(left);

        int right = DFS(root->right);
        if(right != -1)
            answer.push_back(right);

        return root->val;
    }
    int kthSmallest(TreeNode* root, int k) {
        
        int temp = DFS(root);
        answer.push_back(temp);

        sort(answer.begin(), answer.end());

        return answer[k-1];
    }
};
