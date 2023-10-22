class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        
        vector<unsigned> dp(target+1, 0); //Must be unsigned
        dp[0] = 1;
        
        for(int i = 1; i <= target; i++)
        {
            for (int x = 0; x < nums.size(); x++)
            {
                if (i >= nums[x])
                    dp[i] += dp[i-nums[x]];
            }
        }

        return dp[target];
    }
};
