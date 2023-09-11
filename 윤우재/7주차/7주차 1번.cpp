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
    TreeNode* invertTree(TreeNode* root) {
        //재귀 돌리면서 왼쪽 오른쪽 포인터를 스왑해주면 되겠네
        //왼쪽, 오른쪽 둘 중 하나만 nullptr일 경우도 스왑
        if(nullptr == root)return nullptr;
        if(check(root->right) && check(root->left))
        {
            TreeNode* temp = root->right;
            root->right = root->left;
            root->left = temp;
        }
        else
        {
            TreeNode* temp = root->right;
            root->right = root->left;
            root->left = temp;
            invertTree(root->right);
            invertTree(root->left);
        }
        return root;
    }
    bool check(TreeNode* node)
    {
        //현재 swap을 해야할 상황인지? -> 현재 내 노드의 left, right에 각각 불러주자
        if(nullptr == node || (nullptr == node->right && nullptr == node->left))
            return true;
        return false;
    }
};