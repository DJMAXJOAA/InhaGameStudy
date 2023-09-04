class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {

        int tmp1;
        int tmp2;
        int n = matrix.size();

        for (int j = 0; j < n / 2; j++)
        {
            for (int i = j; i < n - j - 1; i++)
            {
                tmp1 = matrix[j][i];
                matrix[j][i] = matrix[n - i - 1][j];
                tmp2 = matrix[i][n - j - 1];
                matrix[i][n - j - 1] = tmp1;
                tmp1 = matrix[n - j - 1][n - i - 1];
                matrix[n - j - 1][n - i - 1] = tmp2;
                matrix[n - i - 1][j] = tmp1;
            }
        }
    }
};