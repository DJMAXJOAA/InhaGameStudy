//�� ������ Ʈ���� � ������ε� ��ȸ���� ��, �� ���� �ִ븦 ���ϴ� �����̴�.
// ��� �Լ��� ���� return������ �ڱ� �ڽ��� �����ؼ� child �������θ� �̷���� �ִ��� �Ѱܼ�
// ���� �ڽ��� return�� + �ڽ��� ���� ���ؼ� ���� ã�´�.
class Solution {
public:
    int ans = -1000;
    int maxPathSum(TreeNode* root) {
        find(root);
        return ans;
    }
private:
    int find(TreeNode* root) {
        if (root == nullptr) return 0;
        int l = max(find(root->left), 0);
        int r = max(find(root->right), 0);
        ans = max(ans, l + r + root->val);

        return max(l, r) + root->val;
    }
};