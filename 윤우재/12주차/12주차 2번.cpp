class Solution {
public:
    int rob(vector<int>& nums) {
        vector<int> dp(nums.size()+1);
        dp[0] = 0;//첫 집을 털지 않은 경우
        dp[1] = nums[0];//첫 집을 턴 경우
        for(int i = 1; i<nums.size();i++)
        {
            //두 번째 집의 경우부터 시작 -> 
            //dp[2] : 집이 두 개 있을 때의 최대
            //이전에 안 털고 현재 집을 턴 경우와 직전에 털고 지금 털지 않는 경우의 최대
            dp[i+1] = max(dp[i-1]+nums[i], dp[i]);
        }
        return dp[nums.size()];
    }
};