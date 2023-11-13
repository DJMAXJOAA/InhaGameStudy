[15���� 1��] / Validate Binary Search Tree / https://leetcode.com/problems/validate-binary-search-tree/description/

[���� ����]
��� �˰��� = ��� �׷��� ��ȸ
1. ����, ������ �� ��忡 ���� �ּ�, �ִ밪 ���� Ȯ��

[�̽� �� ������]
1. ó���� �迭�� ����������, ������ �ſ� ���� ��Ƹ��� + �ݺ����� �۾�->�迭�� �״�� �ΰ�, �ε����θ� ó���Ͽ� �ذ� ����
2. ���� ��ȸ �迭�� �ε����� ã�� �� ���� �˻��ϴ� ���, �� ���� ���⵵�� O(n ^ 2)�� �ȴ�->�ε����� �˻��� �ؽ� ������ �̸� ����Ͽ� Ư�� �ε����� ȿ�������� ���� �����ϴ�.
3. ó���� unordered_map<int, TreeNode*>�� �̸� �� �������� �������� -> ���� ó���� ������ ������ ��Ģ�� ó���ϱ� �ſ� ���������.

[�ٸ� Ǯ�� ���]
1. ���� ��ȸ

Runtime 4ms
Beats 91.79 % of users with C++
Memory 21.96MB
Beats 84.45 % of users with C++

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
        bool CompareTree(TreeNode* root, TreeNode* min, TreeNode* max)
        {
            if (root == nullptr) return true;

            if ((min != nullptr && root->val <= min->val) || (max != nullptr) && root->val >= max->val)
                return false;

            return CompareTree(root->left, min, root) && CompareTree(root->right, root, max);
        }

        bool isValidBST(TreeNode* root) {
            return CompareTree(root, nullptr, nullptr);
        }
};

[�ٸ� Ǯ�� ���]
���� ��ȸ
1. ���� ��ȸ���� �� �׻� ����� ���������̾�� �Ѵ�
2. �� ������ �̿��ؼ� BST Ʈ���� ������ ���Ѵ�

class Solution {
public:
    TreeNode* prev = nullptr;

    bool isValidBST(TreeNode* root) 
    {
        if (root == nullptr) return true;

        // ���� ����Ʈ�� Ž��
        if (!isValidBST(root->left)) return false;

        // ���� ��� �˻� (���� ��ȸ)
        if (prev != nullptr && root->val <= prev->val) return false;
        prev = root;

        // ������ ����Ʈ�� Ž��
        return isValidBST(root->right);
    }
};
