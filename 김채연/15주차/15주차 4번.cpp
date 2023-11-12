class Solution {
public:
	void AddAllElement(vector<int>& node_val_vec, TreeNode* root) {
		if (root == nullptr) return;

		if (root->left) AddAllElement(node_val_vec, root->left);
		node_val_vec.push_back(root->val);
		if (root->right) AddAllElement(node_val_vec, root->right);
	}
	int kthSmallest(TreeNode* root, int k) {
		vector<int> node_val_vec;
		AddAllElement(node_val_vec, root);

		return node_val_vec[k - 1];
	}
};