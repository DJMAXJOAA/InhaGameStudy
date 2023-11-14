/*
 https://leetcode.com/problems/validate-binary-search-tree/description/
 98. Validate Binary Search Tree
 Given the root of a binary tree, determine if it is a valid binary search tree (BST).

 A valid BST is defined as follows:

 The left
 subtree
  of a node contains only nodes with keys less than the node's key.
 The right subtree of a node contains only nodes with keys greater than the node's key.
 Both the left and right subtrees must also be binary search trees.
  

 Example 1:


 Input: root = [2,1,3]
 Output: true
 Example 2:

1,2a,3,4a,5,6,7,8a,9,10,11,12,13,14,15,16a,17,18
 Input: root = [5,1,4,null,null,3,6]
 Output: false
 Explanation: The root node's value is 5 but its right child's value is 4.
  

 Constraints:

 The number of nodes in the tree is in the range [1, 104].
 -231 <= Node.val <= 231 - 1
 
 
 
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        
    }
};

*/
/*
 BST : binary search tree 이진 탐색 트리
 root 기준 작은 숫자 왼쪽, 큰 숫자 오른쪽에 있는 트리
 */
class Solution {
public:
    vector<int> nodes;
    void inorder(TreeNode* root)
    {
        if(root->left!=nullptr)
        {
            inorder(root->left);
        }
        nodes.push_back(root->val);
        if(root->right!=nullptr)
        {
            inorder(root->right);
        }
        
    }
    bool isValidBST(TreeNode* root) {
        inorder(root);
        for(int i=0; i<nodes.size()-1;i++)
        {
            if(nodes[i]>=nodes[i+1])
                return false;
        }
        return true;
    }
};
