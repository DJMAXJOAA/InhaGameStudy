class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        bool isCol = false, isRow = false;
        int m = matrix.size();
        int n = matrix[0].size();

        // 첫번째 열 0 체크
        for (int i = 0; i < m; i++)
        {
            if (matrix[i][0] == 0)
            {
                isCol = true;
                break;
            }
        }

        // 첫번째 행 0 체크
        for (int j = 0; j < n; j++)
        {
            if (matrix[0][j] == 0)
            {
                isRow = true;
                break;
            }
        }

        // 나머지 행렬 0 체크
        for (int i = 1; i < m; i++)
        {
            for (int j = 1; j < n; j++)
            {
                if (matrix[i][j] == 0)
                {
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }

        // 나머지 행렬 0 마킹
        for (int i = 1; i < m; i++)
        {
            for (int j = 1; j < n; j++)
            {
                if (matrix[i][0] == 0 || matrix[0][j] == 0)
                {
                    matrix[i][j] = 0;
                }
            }
        }

        // 첫번째 행 0 마킹
        if (isRow)
        {
            for (int j = 0; j < n; j++)
            {
                matrix[0][j] = 0;
            }
        }

        // 첫번째 열 0 마킹
        if (isCol)
        {
            for (int i = 0; i < m; i++)
            {
                matrix[i][0] = 0;
            }
        }
    }
};