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
    TreeNode* subtree(vector<int>& preorder, vector<int>& inorder, int& pre, int left, int right)
    {
        if(left > right)    return NULL;

        int in = left;
        while(preorder[pre] != inorder[in]) // root노드가 될 value값 inorder에서 찾기
            in++;
        
        pre++;

        TreeNode* temp = new TreeNode(inorder[in]);

        // pre값을 높여줘서 다음 root값이 될 노드 탐색
        temp->left = subtree(preorder, inorder, pre, left, in-1);   // in기준 왼쪽 subtree
        temp->right = subtree(preorder, inorder, pre, in+1, right); // in기준 오른쪽 subtree

        return temp;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        
        int pre = 0;
        return subtree(preorder, inorder, pre, 0, inorder.size()-1);
    }
};
