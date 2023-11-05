[14���� 1��] / Construct Binary Tree from Preorder and Inorder Traversal / 1�ð� 57�� / https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/description/

[���� ����]
��� �˰��� = ���� ����(+�ؽ� ��, Ʈ�� ��ȸ) : O(n), O(n)
1. ���� ��ȸ�� ���� ��ȸ�� root ����� ��ġ�� �ٸ� -> �� �κ��� �̿��� left ���� right ����� ��ġ ��Ģ�� �� �� ����
2. ���� ��ȸ �迭�� root node �ε��� ��ġ �˻�
3. ����� ���� ��ȸ �迭���� ��Ģ�� �°� ���ؼ�, left�� right�� �����Ŵ

[�̽� �� ������]
1. ó���� �迭�� ����������, ������ �ſ� ���� ��Ƹ��� + �ݺ����� �۾�->�迭�� �״�� �ΰ�, �ε����θ� ó���Ͽ� �ذ� ����
2. ���� ��ȸ �迭�� �ε����� ã�� �� ���� �˻��ϴ� ���, �� ���� ���⵵�� O(n ^ 2)�� �ȴ�->�ε����� �˻��� �ؽ� ������ �̸� ����Ͽ� Ư�� �ε����� ȿ�������� ���� �����ϴ�.
3. ó���� unordered_map<int, TreeNode*>�� �̸� �� �������� �������� -> ���� ó���� ������ ������ ��Ģ�� ó���ϱ� �ſ� ���������.

[�ٸ� Ǯ�� ���]

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
//���� 3 / 9, 10, 22, 14 / 20, 15, 7, 31
//���� 22, 10, 9, 14 / 3 / 15, 20, 31, 7
//���� 22, 10, 14, 9 / 15, 31, 7, 20 / 3 �̰� �Ⱦ�


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

            // preorder ������ ù �ε��� + 1
            root->left = PreOrder(preStart + 1, preStart + leftDistance, inStart, findIndex - 1,
                preorder, inorder, mp);

            // preorder ������ �˻� �Ϸ� �� + 1
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