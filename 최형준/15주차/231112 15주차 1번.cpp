[15주차 1번] / Validate Binary Search Tree / https://leetcode.com/problems/validate-binary-search-tree/description/

[문제 접근]
사용 알고리즘 = 재귀 그래프 순회
1. 왼쪽, 오른쪽 각 노드에 대해 최소, 최대값 범위 확인

[이슈 및 개선점]
1. 처음에 배열로 접근했으나, 공간을 매우 많이 잡아먹음 + 반복적인 작업->배열은 그대로 두고, 인덱스로만 처리하여 해결 가능
2. 중위 순회 배열의 인덱스를 찾을 때 선형 검색하는 경우, 이 때의 복잡도는 O(n ^ 2)이 된다->인덱스의 검색을 해시 맵으로 미리 등록하여 특정 인덱스를 효율적으로 접근 가능하다.
3. 처음에 unordered_map<int, TreeNode*>로 미리 다 만들어놓고 시작했음 -> 문제 처리가 가능은 하지만 규칙을 처리하기 매우 어려워진다.

[다른 풀이 방법]
1. 중위 순회

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

[다른 풀이 방법]
중위 순회
1. 중위 순회했을 때 항상 결과가 오름차순이어야 한다
2. 이 조건을 이용해서 BST 트리의 값들을 비교한다

class Solution {
public:
    TreeNode* prev = nullptr;

    bool isValidBST(TreeNode* root) 
    {
        if (root == nullptr) return true;

        // 왼쪽 서브트리 탐색
        if (!isValidBST(root->left)) return false;

        // 현재 노드 검사 (중위 순회)
        if (prev != nullptr && root->val <= prev->val) return false;
        prev = root;

        // 오른쪽 서브트리 탐색
        return isValidBST(root->right);
    }
};
