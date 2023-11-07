class Solution {
public:
    int countSubstrings(string s)
    {
        int ans = 0;
        int n = s.size();
        int dp[n][n];
        memset(dp, false, sizeof(dp));

        for (int i = 0; i < n; i++)
        {
            dp[i][i] = true;
            ans++;
        }

        for (int i = 0; i < n - 1; i++)
        {
            if (s[i] == s[i + 1])
            {
                dp[i][i + 1] = true;
                ans++;
            }
        }

        for (int i = n - 1; i >= 0; i--)      // start
        {
            for (int j = i; j < n; j++)  // end
            {
                if (dp[i][j]) continue;
                else
                {
                    if (dp[i + 1][j - 1] && (s[i] == s[j]))
                    {
                        dp[i][j] = true;
                        ans++;
                    }
                }
            }
        }

        return ans;
    }
};