[9주차 2번] / Binary Tree Maximum Path Sum / 56분 / https://leetcode.com/problems/binary-tree-maximum-path-sum/

[문제 접근]
사용 알고리즘 = DFS, 후위 순회 (분할 정복 알고리즘)
1. 트리를 후위 순회 한다
2. 자식 노드가 둘 다 있는 경우 -> 현재 노드의 val값 + 자식 노드들의 val값들을 max값과 비교
3. 하나만 있거나 없는 경우 -> 현재 노드의 val값을 갱신하고, max값과 비교
(이 과정을 반복한다면 작은 트리들이 결국에는 하나의 트리가 된다)

[개선점]
1. 조건을 여러번 체크할 필요 없이 코드를 간결하게 할 수 있음

[다른 풀이 방법]
1. DP (동적 프로그래밍)

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

[개선점]
1. 조건을 여러번 체크할 필요 없이 코드를 간결하게 할 수 있음

class Solution {
public:
    int result = INT_MIN;

    int maxPathSumHelper(TreeNode* root) {
        if (!root) return 0;

        int left = max(0, maxPathSumHelper(root->left));   // 음수 값을 갖는 경로는 무시
        int right = max(0, maxPathSumHelper(root->right)); // 음수 값을 갖는 경로는 무시

        result = max(result, left + right + root->val);  // 현재 노드를 거쳐 가는 최대 경로 합계 업데이트

        return root->val + max(left, right); // 현재 노드를 시작점으로 하는 최대 경로 합계
    }

    int maxPathSum(TreeNode* root) {
        maxPathSumHelper(root);
        return result;
    }
};


[다른 풀이 방법]
DP(동적 프로그래밍)
1. 1차로 트리를 전부 순회해서 최대 경로 합계를 저장하는 배열을 만든다
2. 만들었던 배열을 순회하면서 배열 안에 있는 값 중 최대값을 구한다
(분할 정복 풀이와 dp 배열이 생긴것 외에는 동일하다)

class Solution {
public:
    unordered_map<TreeNode*, int> dp;
    int result = INT_MIN;

    int maxPathSumHelper(TreeNode* root) {
        if (!root) return 0;

        // 왼쪽 서브트리의 최대 경로 합계
        int left = max(0, maxPathSumHelper(root->left));

        // 오른쪽 서브트리의 최대 경로 합계
        int right = max(0, maxPathSumHelper(root->right));

        // 현재 노드를 기준으로 하는 최대 경로 합계를 계산하고 결과 업데이트
        result = max(result, left + right + root->val);

        // dp 배열에 현재 노드에서 시작하는 경로의 최대 합계 저장
        dp[root] = root->val + max(left, right);

        return dp[root];
    }

    int maxPathSum(TreeNode* root) {
        maxPathSumHelper(root);
        return result;
    }
};
