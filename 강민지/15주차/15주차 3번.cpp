class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<int> row(n, 1);

        vector<vector<int>> answer(m, row);

        for(int i = 1; i < m; i++)
        {
            for(int j = 1; j < n; j++)
            {
                answer[i][j] = answer[i-1][j] + answer[i][j-1];
            }
        }

        return answer[m-1][n-1];
    }
};
