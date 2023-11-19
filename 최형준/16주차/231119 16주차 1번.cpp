[16주차 1번] / Lowest Common Ancestor of a Binary Search Tree / https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree/description/

[문제 접근]
사용 알고리즘 = 재귀 그래프 순회 O(n^2), O(n)
1. 후위 순회로 노드들을 큐에 저장
2. 후위 순회로 공통의 부모를 가지는 노드를 찾음

[이슈 및 개선점]
1. 이진 탐색 트리의 속성 (왼쪽 < 중간 < 오른쪽)을 전혀 사용하지 않고, 직접 찾았음 -> 매우 비효율적이다
2. 공통의 부모 노드를 찾기 위해서 저장 공간과 각각의 탐색을 사용했으나, 필요 없는 과정 (직접 값을 비교하는게 좋음)
3. 탐색에서 겹치는 부분이 아주 많음

[다른 풀이 방법]
1. 각 노드들의 값들을 비교해서 구하기(BST 특성 이용)
2. 두 노드의 경로를 찾고 마지막 공통 노드로 결정

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

[다른 풀이 방법]
각 노드들의 값들을 비교해서 구하기(BST 특성)
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


두 노드의 경로를 찾고 마지막 공통 노드로 결정
class Solution {
public:
    // 루트에서 k까지의 경로를 찾는 함수
    bool findPath(TreeNode* root, vector<TreeNode*>& path, int k) {
        // 현재 노드가 NULL이면 실패
        if (root == NULL) return false;

        // 현재 노드를 경로에 추가
        path.push_back(root);

        // 현재 노드가 목표 노드면 성공
        if (root->val == k) return true;

        // 왼쪽 또는 오른쪽 자식에서 경로를 찾으면 성공
        if ((root->left && findPath(root->left, path, k)) ||
            (root->right && findPath(root->right, path, k)))
            return true;

        // 현재 노드에서 경로를 찾지 못하면, 경로에서 제거하고 실패 반환
        path.pop_back();
        return false;
    }

    // 두 노드 p와 q의 최소 공통 조상을 찾는 함수
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*> path1, path2;

        // p와 q까지의 경로를 찾음
        if (!findPath(root, path1, p->val) || !findPath(root, path2, q->val))
            return NULL;

        // 두 경로를 비교하여 최초로 다른 점이 나타나는 노드 직전의 노드 반환
        int i;
        for (i = 0; i < path1.size() && i < path2.size(); i++) {
            if (path1[i] != path2[i])
                break;
        }

        return path1[i - 1];
    }
};
