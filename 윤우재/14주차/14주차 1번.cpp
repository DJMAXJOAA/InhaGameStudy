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
    int curRootIdx = 0;
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        //preorder의 첫 원소는 root
        //inorder에서 root원소를 찾고, 왼쪽과 오른쪽을 구분
        //iterator 돌리면 root기준 왼쪽 노드의 사이즈를 구할 수 있음

        if(preorder.empty() || inorder.empty())
            return nullptr;
        TreeNode* root = new TreeNode(preorder[0]);
        auto it = find(inorder.begin(), inorder.end(),preorder[0]);
        int leftSize = distance(inorder.begin(), it);
        
        vector<int> leftPreorder(preorder.begin()+1, preorder.begin()+1+leftSize);
        vector<int> leftInorder(inorder.begin(), it);
        vector<int> rightPreorder(preorder.begin()+1+leftSize, preorder.end());
        vector<int> rightInorder(it+1, inorder.end());

        root->left = buildTree(leftPreorder, leftInorder);
        root->right = buildTree(rightPreorder, rightInorder);

        return root;
    }
    
    
};