class Solution {
public:
    int climbStairs(int n) {
        int dp[46];
        dp[0] = dp[1] = 1;
        dp[2] = 2;
        int c = 1;
        for(int i = 3; i<n+1;i++)
        {
            dp[i] = dp[i-1] + dp[i-2];
            c++;
        }
        return dp[n];
    }
};