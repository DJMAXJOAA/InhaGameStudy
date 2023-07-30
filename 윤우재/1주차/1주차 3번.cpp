class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) 
    {
        int row = matrix.size();
        int col = matrix[0].size();

        bool isTopZero, isLeftZero;
        isTopZero = isLeftZero = false;

        for(int i = 0;i<row;i++)
        {
            if(!matrix[i][0])
            {
                isLeftZero = true;
                break;
            }
        }
        for(int i = 0; i<col;i++)
        {
            if(!matrix[0][i])
            {
                isTopZero = true;
            }
        }

        for(int i = 1; i<row;i++)
        {
            for(int j = 1; j<col;j++)
            {
                if(!matrix[i][j])
                {
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }

        for(int i = 1; i<row;i++)
        {
            if(!matrix[i][0])
            {
                for(int j = 1; j<col;j++)
                    matrix[i][j] =0;
            }
        }
            
        
        for(int j = 1; j<col;j++)
        {
            if(!matrix[0][j])
            {
                for(int i = 1; i<row;i++)
                    matrix[i][j] =0;
            }
        }
        
        if(isLeftZero)
        {
            for(int i = 0; i<row;i++)
            {
                matrix[i][0] = 0;
            }
        }
        if(isTopZero)
        {
            for(int j = 0; j<col;j++)
            {
                matrix[0][j] = 0;
            }
        }


    }
};