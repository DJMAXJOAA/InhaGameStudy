//이 문제는 트리를 어떤 방식으로든 순회했을 때, 그 합의 최대를 구하는 문제이다.
// 재귀 함수를 통해 return값으로 자기 자신을 포함해서 child 방향으로만 이루어진 최댓값을 넘겨서
// 양쪽 자식의 return값 + 자신의 값을 비교해서 답을 찾는다.
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