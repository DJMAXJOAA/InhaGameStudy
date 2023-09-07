[6주차 1번] / Invert Binary Tree / 5분 / https://leetcode.com/problems/invert-binary-tree/

[문제 접근]
사용 알고리즘 = 트리의 후위 순회
1. 트리를 후위 순회 -> 가장 하위의 자식들부터 자식 노드의 위치를 서로 바꾼다

[개선점]
1.  함수를 세개 사용했는데, nullptr 체크와 함수의 불필요한 호출이 있음, 하나의 함수로 해결 가능
    순회와 스왑을 동시에 해결

[다른 풀이 방법]
1. BFS나 DFS를 이용하는 방법(큐나 스택 사용)

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


[개선점]
1.  함수를 세개 사용했는데, nullptr 체크와 함수의 불필요한 호출이 있음, 하나의 함수로 해결 가능
    순회와 스왑을 동시에 해결

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

[다른 풀이 방법]
1. BFS나 DFS를 이용하는 방법(큐나 스택 사용)
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if (!root) return nullptr;

        queue<TreeNode*> q;
        q.push(root);
        while (true)
        {
            // front -> top 바꾸고, queue를 stack으로 하면 DFS
            TreeNode* current = q.front();
            q.pop();

            swap(current->left, current->right);
            if (current->left) q.push(current->left);
            if (current->right) q.push(current->right);
        }

        return root;

    }
};