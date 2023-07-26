class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix)
    {
        int x = matrix.size();
        int y = matrix[0].size();

        vector<int> col;
        vector<int> row;

        for (int i = 0; i < x; i++)
        {
            for (int j = 0; j < y; j++)
            {
                if (matrix[i][j] == 0)
                {
                    col.push_back(i);
                    row.push_back(j);
                }
            }
        }

        while (!col.empty())
        {
            for (int j = 0; j < y; j++)
            {
                matrix[col.back()][j] = 0;
            }

            col.pop_back();
        }

        while (!row.empty())
        {
            for (int j = 0; j < x; j++)
            {
                matrix[j][row.back()] = 0;
            }

            row.pop_back();
        }

    }
};