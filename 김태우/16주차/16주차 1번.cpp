/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution
{
public:
    void ValIndex(TreeNode* node, int val, vector<TreeNode*>& temp)
    {
        if (node == NULL) return;
        temp.push_back(node);
        if (node->val == val) return;

        if (node->val < val)
        {
            ValIndex(node->right, val, temp);
        }

        else
        {
            ValIndex(node->left, val, temp);
        }
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q)
    {
        vector<TreeNode*> pVal;
        vector<TreeNode*> qVal;

        ValIndex(root, p->val, pVal);
        ValIndex(root, q->val, qVal);

        TreeNode* ans = pVal[0];

        int n = min(pVal.size(), qVal.size());

        for (int i = 1; i < n; i++)
        {
            if (pVal[i]->val == qVal[i]->val)
            {
                ans = pVal[i];
            }

            else
            {
                break;
            }
        }

        return ans;




    }
};