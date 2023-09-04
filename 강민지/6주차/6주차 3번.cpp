class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        
        int row = matrix.size();
        int col = matrix[0].size();

        // 대각선 이동
        for(int i = 0; i < row; i++)
        {
            for(int j = i; j < col; j++)
            {
                int temp = matrix[i][j];
                matrix[i][j] = matrix[j][i];
                matrix[j][i] = temp;
            }   
        }

        // 좌우 이동
        for(int i = 0; i < row; i++)
        {
            for(int j = 0; j < col/2; j++)
            {
                int temp = matrix[i][j];
                matrix[i][j] = matrix[i][col-1-j];
                matrix[i][col-1-j] = temp;
            }
        }

    }
};
