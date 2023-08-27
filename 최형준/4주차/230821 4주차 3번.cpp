[4���� 3��] / Same Tree / 14�� / https://leetcode.com/problems/same-tree/
��ȸ�� ���鼭

���� ����
1. ���� ��ȸ�� ����ؼ� ���Ϳ� ��ȸ�� ���鼭 ������ ����
2. �ΰ��� Ʈ���� ���� ��ȸ
3. ���� �����̳��� �񱳿������� �� ���͸� ��

���� ����
1. ��ȸ�� �ѹ� ���鼭�� ������ Ǯ �� �ִ�. (������ ���غ��� �ƴ�����.. ���� ���غ� ����̶� �õ� ���غ���)

// Time taken : 14 m 55 s
// Runtime 3ms
// Beats 43.53 % of users with C++
// Memory 10.52MB
// Beats 8.18 % of users with C++

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
        void preTraverse(TreeNode* node, vector<int>& vec)
        {
            if (node == nullptr)
            {
                vec.push_back(1000001); // nullptr ǥ���
                return;
            }

            vec.push_back(node->val);
            preTraverse(node->left, vec);
            preTraverse(node->right, vec);
        }

        bool isSameTree(TreeNode* p, TreeNode* q) {
            vector<int> vecP;
            vector<int> vecQ;

            preTraverse(p, vecP);
            preTraverse(q, vecQ);

            if (vecP == vecQ)
                return true;
            else
                return false;
        }
};