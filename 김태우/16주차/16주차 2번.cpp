class Solution {
public:
    bool canJump(vector<int>& nums)
    {
        int n = nums.size();

        bool dp[n];
        memset(dp, false, sizeof(dp));

        for (int i = 0; i <= nums[0]; i++)
        {
            dp[i] = true;
            if (dp[n - 1]) return true;
        }

        for (int i = 1; i < n; i++)
        {
            if (dp[i])
            {
                for (int j = i; j <= i + nums[i]; j++)
                {
                    dp[j] = true;
                    if (dp[n - 1]) return true;
                }
            }
        }

        return dp[n - 1];
    }
};