[9���� 2��] / Binary Tree Maximum Path Sum / 56�� / https://leetcode.com/problems/binary-tree-maximum-path-sum/

[���� ����]
��� �˰��� = DFS, ���� ��ȸ (���� ���� �˰���)
1. Ʈ���� ���� ��ȸ �Ѵ�
2. �ڽ� ��尡 �� �� �ִ� ��� -> ���� ����� val�� + �ڽ� ������ val������ max���� ��
3. �ϳ��� �ְų� ���� ��� -> ���� ����� val���� �����ϰ�, max���� ��
(�� ������ �ݺ��Ѵٸ� ���� Ʈ������ �ᱹ���� �ϳ��� Ʈ���� �ȴ�)

[������]
1. ������ ������ üũ�� �ʿ� ���� �ڵ带 �����ϰ� �� �� ����

[�ٸ� Ǯ�� ���]
1. DP (���� ���α׷���)

Runtime 14ms
Beats 92.64 % of users with C++
Memory 28.7MB
Beats 8.13 % of users with C++

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
        int result = -1001;

        void PostOrederTraversal(TreeNode* root)
        {
            if (root == nullptr) return;
            PostOrederTraversal(root->left);
            PostOrederTraversal(root->right);

            TreeNode* left = root->left;
            TreeNode* right = root->right;
            if (left != nullptr && right != nullptr)
            {
                result = max(result, left->val + root->val + right->val);

                root->val = max(root->val, root->val + max(left->val, right->val));
                result = max(result, root->val);
            }
            else if (left != nullptr)
            {
                root->val = max(root->val, root->val + left->val);
                result = max(result, root->val);
            }
            else if (right != nullptr)
            {
                root->val = max(root->val, root->val + right->val);
                result = max(result, root->val);
            }
            else
            {
                result = max(result, root->val);
            }
        }

        int maxPathSum(TreeNode* root)
        {
            PostOrederTraversal(root);
            return result;
        }
};

[������]
1. ������ ������ üũ�� �ʿ� ���� �ڵ带 �����ϰ� �� �� ����

class Solution {
public:
    int result = INT_MIN;

    int maxPathSumHelper(TreeNode* root) {
        if (!root) return 0;

        int left = max(0, maxPathSumHelper(root->left));   // ���� ���� ���� ��δ� ����
        int right = max(0, maxPathSumHelper(root->right)); // ���� ���� ���� ��δ� ����

        result = max(result, left + right + root->val);  // ���� ��带 ���� ���� �ִ� ��� �հ� ������Ʈ

        return root->val + max(left, right); // ���� ��带 ���������� �ϴ� �ִ� ��� �հ�
    }

    int maxPathSum(TreeNode* root) {
        maxPathSumHelper(root);
        return result;
    }
};


[�ٸ� Ǯ�� ���]
DP(���� ���α׷���)
1. 1���� Ʈ���� ���� ��ȸ�ؼ� �ִ� ��� �հ踦 �����ϴ� �迭�� �����
2. ������� �迭�� ��ȸ�ϸ鼭 �迭 �ȿ� �ִ� �� �� �ִ밪�� ���Ѵ�
(���� ���� Ǯ�̿� dp �迭�� ����� �ܿ��� �����ϴ�)

class Solution {
public:
    unordered_map<TreeNode*, int> dp;
    int result = INT_MIN;

    int maxPathSumHelper(TreeNode* root) {
        if (!root) return 0;

        // ���� ����Ʈ���� �ִ� ��� �հ�
        int left = max(0, maxPathSumHelper(root->left));

        // ������ ����Ʈ���� �ִ� ��� �հ�
        int right = max(0, maxPathSumHelper(root->right));

        // ���� ��带 �������� �ϴ� �ִ� ��� �հ踦 ����ϰ� ��� ������Ʈ
        result = max(result, left + right + root->val);

        // dp �迭�� ���� ��忡�� �����ϴ� ����� �ִ� �հ� ����
        dp[root] = root->val + max(left, right);

        return dp[root];
    }

    int maxPathSum(TreeNode* root) {
        maxPathSumHelper(root);
        return result;
    }
};
