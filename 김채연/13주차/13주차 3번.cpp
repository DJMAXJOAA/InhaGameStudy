
//ù��°���� ���������� �����ϴٴ� ���� �߰�.
//��Ʈ�ڵ� ��Ʈ ����.
class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, 0);
        vector<int> dp2(n + 1, 0);

        if (n == 1)
            return nums[0];

        for (int i = 2; i < n + 1; i++) {

            if (i > 2)
                dp2[i] = max(nums[i - 1] + dp2[i - 2], dp2[i - 1]);
            else
                dp2[i] = max(nums[i - 1], dp2[i - 1]);

        }
        for (int i = 1; i < n; i++) {

            if (i > 1)
                dp[i] = max(nums[i - 1] + dp[i - 2], dp[i - 1]);
            else
                dp[i] = max(nums[i - 1], dp[i - 1]);
        }

        return max(dp[n - 1], dp2[n]);
    }
};