class Solution {
public:
    int ans = 0;
    int INF = -1;
    int dp[1001];

    int dfs(vector<int>& nums, int target, int sum) {
        if(sum > target) return 0;

        if(sum == target) {
            return dp[sum] = 1;
        }

        if(dp[sum] != INF) return dp[sum];

        dp[sum] = 0;
        for(int i=0; i<nums.size(); i++) {
            dp[sum] += dfs(nums, target, sum + nums[i]);
        }

        return dp[sum];
    }

    // dp[sum]: sum을 만들 수 있는 숫자 조합의 개수
    // INF = -1
    int combinationSum4(vector<int>& nums, int target) {
        fill(dp, dp+1001, INF);
        return dfs(nums, target, 0);
    }
};