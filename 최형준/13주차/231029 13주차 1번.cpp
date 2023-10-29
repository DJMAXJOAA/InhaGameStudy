[13���� 1��] / Subtree of Another Tree / 41�� / https://leetcode.com/problems/subtree-of-another-tree/description/

[���� ����]
��� �˰��� = DFS ���� ��ȸ : O(m * n)
1. isSubtree()���� ���� ��ȸ ����
2. �� ��͸��� Travel()���� �߰� ���� ��ȸ ����

[�߰� ����]
1. �ش� ������ DFS ���� ��ȸ�� Ǫ�� ���� ���� �������̴�. -> ��Ʈ ������ �����ؼ� ���� Ʈ���� ������ ���ϴ� ���� (�� Ʈ���� ��ü�� ���ؾ� �ϴ� ����)
2. ���� ��ȸ : Ʈ���� ���� ǥ��, Ʈ���� ���� / ���� ��ȸ : ���� �˻� Ʈ��, ���������� �ַ� ��� / ���� ��ȸ : Ʈ���� �����ų� ��带 ������ ��
3. BFS : �ִ� ��� ã��, �ּ� ���� ���, ����� ������ ������ ó��

[�ٸ� Ǯ�� ���]
1. DFS ���� ��ȸ
2. DFS ���� ��ȸ
3. BFS

Time taken : 41 m 23 s 
Runtime 18ms
Beats 60.70 % of users with C++
Memory 29.14MB
Beats 40.49 % of users with C++

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
        bool Travel(TreeNode* root, TreeNode* subRoot)
        {
            if (root == nullptr && subRoot == nullptr)
            {
                return true;
            }

            if (root == nullptr || subRoot == nullptr)
            {
                return false;
            }

            if (root->val != subRoot->val)
            {
                return false;
            }

            return Travel(root->left, subRoot->left) && Travel(root->right, subRoot->right);
        }

        bool isSubtree(TreeNode* root, TreeNode* subRoot) {
            if (root == nullptr || subRoot == nullptr)
            {
                return false;
            }

            if (Travel(root, subRoot))
            {
                return true;
            }

            return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
        }
};

[�ٸ� Ǯ�� ���]
1. DFS ���� ��ȸ
class Solution {
public:
    bool isEqual(TreeNode* s, TreeNode* t) {
        if (!s && !t) return true;
        if (!s || !t) return false;
        return s->val == t->val && isEqual(s->left, t->left) && isEqual(s->right, t->right);
    }

    bool checkSubtree(TreeNode* s, TreeNode* t) {
        if (!s) return false;
        if (isEqual(s, t)) return true;
        return checkSubtree(s->left, t) || checkSubtree(s->right, t);
    }

    bool isSubtree(TreeNode* s, TreeNode* t) {
        if (!t) return true;
        return checkSubtree(s, t);
    }
};

2. DFS ���� ��ȸ
class Solution {
public:
    bool isEqual(TreeNode* s, TreeNode* t) {
        if (!s && !t) return true;
        if (!s || !t) return false;
        return isEqual(s->left, t->left) && isEqual(s->right, t->right) && s->val == t->val;
    }

    bool checkSubtree(TreeNode* s, TreeNode* t) {
        if (!s) return false;
        if (isEqual(s, t)) return true;
        return checkSubtree(s->left, t) || checkSubtree(s->right, t);
    }

    bool isSubtree(TreeNode* s, TreeNode* t) {
        if (!t) return true;
        return checkSubtree(s, t);
    }
};

3. BFS
class Solution {
public:
    bool isEqual(TreeNode* s, TreeNode* t) {
        if (!s && !t) return true;
        if (!s || !t) return false;
        return s->val == t->val && isEqual(s->left, t->left) && isEqual(s->right, t->right);
    }

    bool isSubtree(TreeNode* s, TreeNode* t) {
        if (!t) return true;
        if (!s) return false;
        std::queue<TreeNode*> queue;
        queue.push(s);

        while (!queue.empty()) {
            TreeNode* current = queue.front();
            queue.pop();

            if (current->val == t->val) {
                if (isEqual(current, t)) {
                    return true;
                }
            }

            if (current->left) queue.push(current->left);
            if (current->right) queue.push(current->right);
        }

        return false;
    }
};
