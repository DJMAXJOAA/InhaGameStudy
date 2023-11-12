class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n, 0));

        // Initialize the rightmost column and bottom row to 1 because there is only one way to reach each cell in those rows/columns.
        // 도착 지점의 가로 세로 방향들 1로 만들기. -> 한가지 방법들 뿐이니까.
        for (int i = 0; i < m; i++) {
            dp[i][n - 1] = 1;
        }
        for (int j = 0; j < n; j++) {
            dp[m - 1][j] = 1;
        }

        // Fill in the dp table bottom-up 도착 지점에서 시작 지점으로 가는
        for (int i = m - 2; i >= 0; i--) {
            for (int j = n - 2; j >= 0; j--) {
                dp[i][j] = dp[i + 1][j] + dp[i][j + 1];
            }
        }

        return dp[0][0];
    }
};