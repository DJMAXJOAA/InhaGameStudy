// Medium
// Longest Common Subsequence

// LCS(Longest Common Subsequence) '최장 공통 부분 수열'

class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {

        int Cnt = 0;

        for (int i = 0; i < text1.size(); i++)
        {
            for (int j = 0; j < text2.size(); j++)
            {
                if (text1[i] == text2[j])
                {
                    Cnt++;
                }
            }
        }

        return Cnt;
    }
};

class Solution {
public:
    int longestCommonSubsequence(string t1, string t2) {
        int n = t1.size(), m = t2.size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
        for (int j = 0; j <= m; j++) dp[0][j] = 0;
        for (int i = 0; i <= n; i++) dp[i][0] = 0;

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (t1[i - 1] == t2[j - 1]) dp[i][j] = 1 + dp[i - 1][j - 1];
                else dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
            }
        }
        return dp[n][m];
    }
};