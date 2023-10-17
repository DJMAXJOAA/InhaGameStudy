[11���� 1��] / Binary Tree Level Order Traversal / 22�� / https://leetcode.com/problems/binary-tree-level-order-traversal/

[���� ����]
��� �˰��� = BFS
1. depth�� �����ؼ� Ư�� depth�� �ִ� ���鸸 Ž��

Time taken : 22 m 56 s
Runtime 10ms
Beats 13.93 % of users with C++
Memory 13.97MB
Beats 26.48 % of users with C++

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
        vector<vector<int>> levelOrder(TreeNode* root) {
            vector<vector<int>> result;

            if (root == nullptr)
            {
                return result;
            }

            queue<TreeNode*> que;
            que.push(root);

            while (!que.empty())
            {
                int depth = que.size();
                vector<int> arr;
                for (int i = 0; i < depth; i++)
                {
                    TreeNode* temp = que.front();
                    que.pop();

                    arr.push_back(temp->val);

                    if (temp->left != nullptr)
                    {
                        que.push(temp->left);
                    }

                    if (temp->right != nullptr)
                    {
                        que.push(temp->right);
                    }
                }
                result.push_back(arr);
            }

            return result;
        }
};