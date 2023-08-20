[4주차 3번] / Same Tree / 14분 / https://leetcode.com/problems/same-tree/
순회를 돌면서

문제 접근
1. 전위 순회를 사용해서 벡터에 순회를 돌면서 값들을 넣음
2. 두개의 트리에 각각 순회
3. 벡터 컨테이너의 비교연산으로 두 벡터를 비교

개선 사항
1. 순회를 한번 돌면서도 문제를 풀 수 있다. (생각을 안해본건 아니지만.. 뭔가 안해본 방법이라 시도 안해봤음)

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
                vec.push_back(1000001); // nullptr 표기용
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