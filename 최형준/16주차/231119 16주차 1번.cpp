[16���� 1��] / Lowest Common Ancestor of a Binary Search Tree / https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree/description/

[���� ����]
��� �˰��� = ��� �׷��� ��ȸ O(n^2), O(n)
1. ���� ��ȸ�� ������ ť�� ����
2. ���� ��ȸ�� ������ �θ� ������ ��带 ã��

[�̽� �� ������]
1. ���� Ž�� Ʈ���� �Ӽ� (���� < �߰� < ������)�� ���� ������� �ʰ�, ���� ã���� -> �ſ� ��ȿ�����̴�
2. ������ �θ� ��带 ã�� ���ؼ� ���� ������ ������ Ž���� ���������, �ʿ� ���� ���� (���� ���� ���ϴ°� ����)
3. Ž������ ��ġ�� �κ��� ���� ����

[�ٸ� Ǯ�� ���]
1. �� ������ ������ ���ؼ� ���ϱ�(BST Ư�� �̿�)
2. �� ����� ��θ� ã�� ������ ���� ���� ����

Time taken : 39 m 17 s
Runtime 34ms
Beats 5.71 % of users with C++
Memory 24.08MB
Beats 15.70 % of users with C++

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

    class Solution {
    public:
        void PostOrder(TreeNode* root, queue<TreeNode*>& queue)
        {
            if (root == nullptr)
                return;

            PostOrder(root->left, queue);
            PostOrder(root->right, queue);
            queue.push(root);
        }

        bool Travel(TreeNode* root, TreeNode* target)
        {
            if (root == nullptr)
                return false;

            if (root->val == target->val)
            {
                return true;
            }

            return Travel(root->left, target) || Travel(root->right, target);
        }

        TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
            TreeNode* result;
            queue<TreeNode*> queue;

            PostOrder(root, queue);

            while (!queue.empty())
            {
                result = queue.front();

                if (Travel(result, p) && Travel(result, q))
                {
                    return result;
                }

                queue.pop();
            }

            return nullptr;
        }
};

[�ٸ� Ǯ�� ���]
�� ������ ������ ���ؼ� ���ϱ�(BST Ư��)
TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    if (root == nullptr) return nullptr;

    if (root->val < p->val && root->val < q->val) {
        return lowestCommonAncestor(root->right, p, q);
    }
    else if (root->val > p->val && root->val > q->val) {
        return lowestCommonAncestor(root->left, p, q);
    }
    else {
        return root;
    }
}


�� ����� ��θ� ã�� ������ ���� ���� ����
class Solution {
public:
    // ��Ʈ���� k������ ��θ� ã�� �Լ�
    bool findPath(TreeNode* root, vector<TreeNode*>& path, int k) {
        // ���� ��尡 NULL�̸� ����
        if (root == NULL) return false;

        // ���� ��带 ��ο� �߰�
        path.push_back(root);

        // ���� ��尡 ��ǥ ���� ����
        if (root->val == k) return true;

        // ���� �Ǵ� ������ �ڽĿ��� ��θ� ã���� ����
        if ((root->left && findPath(root->left, path, k)) ||
            (root->right && findPath(root->right, path, k)))
            return true;

        // ���� ��忡�� ��θ� ã�� ���ϸ�, ��ο��� �����ϰ� ���� ��ȯ
        path.pop_back();
        return false;
    }

    // �� ��� p�� q�� �ּ� ���� ������ ã�� �Լ�
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*> path1, path2;

        // p�� q������ ��θ� ã��
        if (!findPath(root, path1, p->val) || !findPath(root, path2, q->val))
            return NULL;

        // �� ��θ� ���Ͽ� ���ʷ� �ٸ� ���� ��Ÿ���� ��� ������ ��� ��ȯ
        int i;
        for (i = 0; i < path1.size() && i < path2.size(); i++) {
            if (path1[i] != path2[i])
                break;
        }

        return path1[i - 1];
    }
};
