[15ÁÖÂ÷ 3¹ø] / Unique Paths / https://leetcode.com/problems/unique-paths/

class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m + 1, vector<int>(n + 1));
        dp[0][0] = 1;
        dp[0][1] = 1;
        for (int i = 1; i < dp.size(); i++)
        {
            for (int j = 1; j < dp[i].size(); j++)
            {
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }

        return dp[m][n];
    }
};