class Solution {
public:
    int rob(vector<int>& nums)
    {
        int n = nums.size();
        vector<int> dp(n + 2);

        if (n == 1) return nums[0];
        else if (n == 2) return max(nums[0], nums[1]);
        dp[n - 1] = nums[n - 1];

        for (int i = n - 2; i >= 0; i--)
        {
            dp[i] = nums[i] + max(dp[i + 2], dp[i + 3]);
        }

        return max(dp[0], dp[1]);
    }
};