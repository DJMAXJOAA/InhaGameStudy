[14주차 1번] / Construct Binary Tree from Preorder and Inorder Traversal / 1시간 57분 / https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/description/

[문제 접근]
사용 알고리즘 = 분할 정복(+해시 맵, 트리 순회) : O(n), O(n)
1. 전위 순회와 중위 순회의 root 노드의 위치가 다름 -> 이 부분을 이용해 left 노드와 right 노드의 위치 규칙을 알 수 있음
2. 중위 순회 배열의 root node 인덱스 위치 검색
3. 결과를 전위 순회 배열에서 규칙에 맞게 정해서, left와 right를 연결시킴

[이슈 및 개선점]
1. 처음에 배열로 접근했으나, 공간을 매우 많이 잡아먹음 + 반복적인 작업->배열은 그대로 두고, 인덱스로만 처리하여 해결 가능
2. 중위 순회 배열의 인덱스를 찾을 때 선형 검색하는 경우, 이 때의 복잡도는 O(n ^ 2)이 된다->인덱스의 검색을 해시 맵으로 미리 등록하여 특정 인덱스를 효율적으로 접근 가능하다.
3. 처음에 unordered_map<int, TreeNode*>로 미리 다 만들어놓고 시작했음 -> 문제 처리가 가능은 하지만 규칙을 처리하기 매우 어려워진다.

[다른 풀이 방법]

Time taken : 1 hr 57 m 38 s
Runtime 8ms
Beats 90.23 % of users with C++
Memory 26.60MB
Beats 34.23 % of users with C++

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

//https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/solutions/3986683/easy-solution-explanation/
//[3, 9, 10, 22, 14, 20, 15, 7, 31]
//[22, 10, 9, 14, 3, 15, 20, 31, 7]
//[3, 9, 20, 10, 14, 15, 7, 22, null, null, null, null, null, 31]
//
//전위 3 / 9, 10, 22, 14 / 20, 15, 7, 31
//중위 22, 10, 9, 14 / 3 / 15, 20, 31, 7
//후위 22, 10, 14, 9 / 15, 31, 7, 20 / 3 이건 안씀


    class Solution {
    public:
        TreeNode* PreOrder(int preStart, int preEnd, int inStart, int inEnd,
            vector<int>& preorder, vector<int>& inorder, unordered_map<int, int>& mp)
        {
            if (preStart > preEnd || inStart > inEnd)
                return nullptr;

            TreeNode* root = new TreeNode(preorder[preStart]);
            int findIndex = mp[preorder[preStart]];
            int leftDistance = findIndex - inStart;

            // preorder 범위의 첫 인덱스 + 1
            root->left = PreOrder(preStart + 1, preStart + leftDistance, inStart, findIndex - 1,
                preorder, inorder, mp);

            // preorder 범위의 검색 완료 값 + 1
            root->right = PreOrder(preStart + leftDistance + 1, preEnd, findIndex + 1, inEnd,
                preorder, inorder, mp);

            return root;
        }

        TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {

            unordered_map<int, int> mp;

            for (int i = 0; i < inorder.size(); i++)
            {
                mp.insert(make_pair(inorder[i], i));
            }

            TreeNode* root = PreOrder(0, preorder.size() - 1, 0, inorder.size() - 1,
                preorder, inorder, mp);

            return root;
        }
};