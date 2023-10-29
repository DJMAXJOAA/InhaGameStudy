[13주차 1번] / Subtree of Another Tree / 41분 / https://leetcode.com/problems/subtree-of-another-tree/description/

[문제 접근]
사용 알고리즘 = DFS 전위 순회 : O(m * n)
1. isSubtree()에서 전위 순회 진행
2. 각 재귀마다 Travel()에서 추가 전위 순회 진행

[추가 설명]
1. 해당 문제는 DFS 전위 순회로 푸는 것이 가장 직관적이다. -> 루트 노드부터 시작해서 서브 트리의 구조를 비교하는 문제 (각 트리의 전체를 비교해야 하는 문제)
2. 전위 순회 : 트리의 구조 표현, 트리의 복제 / 중위 순회 : 이진 검색 트리, 오름차순에 주로 사용 / 후위 순회 : 트리를 뒤집거나 노드를 삭제할 때
3. BFS : 최단 경로 찾기, 최소 깊이 노드, 노드의 레벨별 데이터 처리

[다른 풀이 방법]
1. DFS 중위 순회
2. DFS 후위 순회
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

[다른 풀이 방법]
1. DFS 중위 순회
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

2. DFS 후위 순회
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
