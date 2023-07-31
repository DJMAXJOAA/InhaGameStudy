class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix)
    {
        bool temp_n = false;
        bool temp_m = false;
        int i, j;

        for (i = 0; i < matrix[0].size(); i++)
        {
            if (matrix[0][i] == 0)
            {
                temp_n = true;
                break;
            }
        }

        for (i = 0; i < matrix.size(); i++)
        {
            if (matrix[i][0] == 0)
            {
                temp_m = true;
                break;
            }
        }
        //
        for (i = 1; i < matrix.size(); i++)
        {
            for (int j = 1; j < matrix[0].size(); j++)
            {
                if (matrix[i][j] == 0)
                {
                    matrix[0][j] = 0;
                    matrix[i][0] = 0;
                }
            }
        }
        //
        for (i = 1; i < matrix[0].size(); i++)
        {
            if (matrix[0][i] == 0)
            {
                for (j = 1; j < matrix.size(); j++)
                {
                    matrix[j][i] = 0;
                }
            }
        }

        for (i = 1; i < matrix.size(); i++)
        {
            if (matrix[i][0] == 0)
            {
                for (j = 1; j < matrix[0].size(); j++)
                {
                    matrix[i][j] = 0;
                }
            }
        }

        if (temp_n == true)
        {
            for (i = 0; i < matrix[0].size(); i++)
            {
                matrix[0][i] = 0;
            }
        }

        if (temp_m == true)
        {
            for (i = 0; i < matrix.size(); i++)
            {
                matrix[i][0] = 0;
            }
        }

    }
};