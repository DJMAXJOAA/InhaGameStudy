[15ÁÖÂ÷ 4¹ø] / Kth Smallest Element in a BST / https://leetcode.com/problems/kth-smallest-element-in-a-bst/description/

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
    void InOrder(TreeNode* root, vector<int>& temp)
    {
        if (root == NULL)
        {
            return;
        }
        InOrder(root->left, temp);
        temp.push_back(root->val);
        InOrder(root->right, temp);
    }

    int kthSmallest(TreeNode* root, int k) {
        vector<int> temp;
        InOrder(root, temp);
        sort(temp.begin(), temp.end());
        return temp[k - 1];
    }
};