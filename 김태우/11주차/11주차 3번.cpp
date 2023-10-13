class Solution {
public:
    int combinationSum4(std::vector<int>& nums, int target)
    {
        vector<unsigned int> dp(target + 1, 0);
        dp[0] = 1;

        // target should reach zero to make sum in nums elements
        for (int i = 1; i <= target; ++i) {
            for (int j = 0; j < nums.size(); j++)
            {
                if (i - nums[j] >= 0) // target should bigger than nums element
                {
                    dp[i] += dp[i - nums[j]]; // add the possible ways (if not, it zero)
                }
            }
        }

        return dp[target];
    }
};