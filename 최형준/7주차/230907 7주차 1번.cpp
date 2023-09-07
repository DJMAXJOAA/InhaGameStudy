[6���� 1��] / Invert Binary Tree / 5�� / https://leetcode.com/problems/invert-binary-tree/

[���� ����]
��� �˰��� = Ʈ���� ���� ��ȸ
1. Ʈ���� ���� ��ȸ -> ���� ������ �ڽĵ���� �ڽ� ����� ��ġ�� ���� �ٲ۴�

[������]
1.  �Լ��� ���� ����ߴµ�, nullptr üũ�� �Լ��� ���ʿ��� ȣ���� ����, �ϳ��� �Լ��� �ذ� ����
    ��ȸ�� ������ ���ÿ� �ذ�

[�ٸ� Ǯ�� ���]
1. BFS�� DFS�� �̿��ϴ� ���(ť�� ���� ���)

Time taken : 3 m 3 s
Runtime 5ms
Beats 20.77 % of users with C++
Memory 9.74MB
Beats 27.07 % of users with C++

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
        void Swap(TreeNode* root)
        {
            if (root == nullptr) return;

            TreeNode* temp = root->left;
            root->left = root->right;
            root->right = temp;
        }

        void Traverse(TreeNode* root)
        {
            if (root == nullptr)
            {
                return;
            }
            Traverse(root->left);
            Traverse(root->right);
            Swap(root);
        }

        TreeNode* invertTree(TreeNode* root) {
            Traverse(root);
            return root;
        }
};


[������]
1.  �Լ��� ���� ����ߴµ�, nullptr üũ�� �Լ��� ���ʿ��� ȣ���� ����, �ϳ��� �Լ��� �ذ� ����
    ��ȸ�� ������ ���ÿ� �ذ�

class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if (!root) return nullptr;

        TreeNode* temp = root->left;
        root->left = invertTree(root->right);
        root->right = invertTree(temp);

        return root;
    }
};

[�ٸ� Ǯ�� ���]
1. BFS�� DFS�� �̿��ϴ� ���(ť�� ���� ���)
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if (!root) return nullptr;

        queue<TreeNode*> q;
        q.push(root);
        while (true)
        {
            // front -> top �ٲٰ�, queue�� stack���� �ϸ� DFS
            TreeNode* current = q.front();
            q.pop();

            swap(current->left, current->right);
            if (current->left) q.push(current->left);
            if (current->right) q.push(current->right);
        }

        return root;

    }
};