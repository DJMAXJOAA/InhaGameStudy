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
public:
    vector<vector<int>> levelOrder(TreeNode* root)
    {
        vector<vector<int>> ans;
        if (root == NULL) return ans;

        vector<int> sameLevel;
        int rank = 0;
        queue<pair<int, TreeNode*>> que;
        que.push({ rank,root });

        while (!que.empty())
        {
            pair<int, TreeNode*> temp = que.front();
            que.pop();
            if (rank == temp.first)
                sameLevel.push_back(temp.second->val);
            else
            {
                ans.push_back(sameLevel);
                sameLevel.clear();
                sameLevel.push_back(temp.second->val);
                rank++;
            }

            if (temp.second->left)
            {
                que.push({ rank + 1,temp.second->left });
            }

            if (temp.second->right)
            {
                que.push({ rank + 1,temp.second->right });
            }

        }

        ans.push_back(sameLevel);


        return ans;
    }
};