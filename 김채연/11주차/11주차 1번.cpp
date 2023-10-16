//BFS�� ����ϰ�, depth�� ���� queue�� node���� �־��ָ� vector�� �����ϰ�, �Ŀ� ����� return�Ѵ�.
//������ ���̶�� �ϸ�, ó�� queue�� ����� size ��ŭ�� vector�� ������ �־�� depth���� ������ �� �� �ִٴ� ���̴�.

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
			int size = q.size(); //				�Ѹ� ����ŭ.
			vector<int> v;

			for (int i = 0; i < size; i++) {
				TreeNode* front = q.front();
				q.pop(); //						q ����ְ�

				v.push_back(front->val); //		vector�� �ش� depth�� �� �־��ְ�
				if (front->left != NULL)
					q.push(front->left); //		�� depth�� ��� �ִ���
				if (front->right != NULL)
					q.push(front->right);
			}

			res.push_back(v);
		}

		reverse(res.begin(), res.end()); //		�� ������?
		return res;
	}
};