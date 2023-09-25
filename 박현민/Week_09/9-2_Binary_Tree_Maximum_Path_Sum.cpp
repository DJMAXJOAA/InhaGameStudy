/*
	DFS
	Runtime: 16 ms ~ 24 ms (82.94% ~ 28.59%)
	Memory: 27.9 MB ~ 28 MB (32.19% ~ 29.3%)
*/

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
	//https://withhamit.tistory.com/60
	//https://www.algodale.com/problems/binary-tree-maximum-path-sum/
	int maxSum = 0;
	int DFS(TreeNode* root) {
		if (root == NULL) return 0;
		// 왼쪽 자식 노드와 연결할지 결정, 음수면 연결 X
		int leftMax = max(DFS(root->left), 0);
		// 오른쪽 자식 노드와 연결할지 결정, 음수면 연결 X
		int rightMax = max(DFS(root->right), 0);

		// 현재 노드와 부모 노드를 연결할지 결정
		maxSum = max(root->val + leftMax + rightMax, maxSum);
		// 좌측이나 우측 자식 트리와 연결을 결정
		return root->val + max(leftMax, rightMax);
	}

	int maxPathSum(TreeNode* root) {
		maxSum = root->val;
		DFS(root);
		return maxSum;
	}
};