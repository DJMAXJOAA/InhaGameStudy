// https://leetcode.com/problems/rotate-image/

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int rows = matrix.size();
        int cols = matrix[0].size();

        for(int i=0; i<rows / 2; i++)
        {
            int st = i;
            int en = rows - 1 - i;

            for(int j=0; j<cols; j++)
            {
                swap(matrix[st][j], matrix[en][j]);
            }
        }

        for(int i=0; i<rows * 2 - 1; i++)
        {
            if(i < rows)
            {
                int x = i;
                int y = 0;

                for(int j=0; j <= i / 2; j++)
                {
                    swap(matrix[x][y], matrix[y][x]);
                    x--;
                    y++;
                }
            }
            else
            {
                int x = rows - 1;
                int y = i - rows + 1;
                int cnt = rows * 2 - i - 1;

                for(int j=0; j<cnt / 2; j++)
                {
                    swap(matrix[x][y], matrix[y][x]);
                    x--;
                    y++;
                }
            }
        }
    }
};
