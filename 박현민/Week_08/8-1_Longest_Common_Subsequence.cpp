/*
    Runtime: 54 ms (49.50%)
    Memory: 24.8 MB (7.32%)
*/

class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        const int m = text1.length();
        const int n = text2.length();
        
        vector<vector<int>> dp(m + 1, vector<int>(n + 1));

        for (int i = 1; i <= m; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (text1[i - 1] == text2[j - 1]) dp[i][j] = 1 + dp[i - 1][j - 1];
                else dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
            }
        }

        return dp[m][n];
    }
};

/*
    Runtime: 14 ms (98.46%)
    Memory: 11.1MB (74.37%)
*/

class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        const int m = text1.length();
        const int n = text2.length();
        int dp[1001][1001];

        for (int i = 1; i <= m; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (text1[i - 1] == text2[j - 1]) dp[i][j] = 1 + dp[i - 1][j - 1];
                else dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
            }
        }

        return dp[m][n];
    }
};