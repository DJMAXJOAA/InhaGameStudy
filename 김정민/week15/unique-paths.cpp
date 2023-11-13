class Solution {
public:
    int uniquePaths(int m, int n) {
        int dp[101][101];
        for(int i=0; i<m; i++)
            fill(dp[i], dp[i]+n, 0);
        
        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                if(i == 0) dp[i][j] = 1;
                else if(j == 0) dp[i][j] = 1;
                else dp[i][j] = dp[i-1][j] + dp[i][j-1];
            }   
        }

        return dp[m-1][n-1];
    }
};