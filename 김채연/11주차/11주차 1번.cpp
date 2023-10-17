//BFS와 비슷하게, depth에 따라 queue에 node들을 넣어주며 vector에 저장하고, 후에 뒤집어서 return한다.
//유의할 점이라고 하면, 처음 queue에 저장된 size 만큼만 vector에 저장해 주어야 depth별로 저장을 할 수 있다는 것이다.

/* CASE 1 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
	vector<vector<int>> levelOrderBottom(TreeNode* root) {
		vector<vector<int>> res;

		if (root == NULL) return res;

		queue<TreeNode*> q;
		q.push(root);

		while (!q.empty()) {
			int size = q.size(); //				뿌리 수만큼.
			vector<int> v;

			for (int i = 0; i < size; i++) {
				TreeNode* front = q.front();
				q.pop(); //						q 비워주고

				v.push_back(front->val); //		vector에 해당 depth의 값 넣어주고
				if (front->left != NULL)
					q.push(front->left); //		그 depth에 몇개가 있는지
				if (front->right != NULL)
					q.push(front->right);
			}

			res.push_back(v);
		}

		reverse(res.begin(), res.end()); //		왜 뒤집지?
		return res;
	}
};