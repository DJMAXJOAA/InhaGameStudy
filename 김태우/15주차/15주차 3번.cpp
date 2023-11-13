class Solution {
public:
    // TimeExceed
    // int Combination(int n, int r)
    // {
    //     if(n==r || r==0) 
    //         return 1;
    //     else
    //         return(Combination(n-1,r-1) + Combination(n-1,r));
    // }

    // int uniquePaths(int m, int n) 
    // {
    //     return Combination(m+n-2, m-1);
    // }

    int uniquePaths(int m, int n)
    {
        int dp[m][n];
        memset(dp, 0, sizeof(dp));

        for (int i = 0; i < m; i++)
        {
            dp[i][0] = 1;
        }

        for (int i = 0; i < n; i++)
        {
            dp[0][i] = 1;
        }

        for (int i = 1; i < m; i++)
        {
            for (int j = 1; j < n; j++)
            {
                dp[i][j] = dp[i][j - 1] + dp[i - 1][j];
            }
        }

        return dp[m - 1][n - 1];

    }


};