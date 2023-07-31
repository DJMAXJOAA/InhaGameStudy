class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        
        vector<int> iLocation;
        vector<int> jLocation;

        for(int i = 0; i < matrix.size(); i++)
        {
            for(int j = 0; j < matrix[0].size(); j++)
            {
                if(matrix[i][j] == 0)
                {
                    iLocation.push_back(i);
                    jLocation.push_back(j);
                }
            }
        }

        if(iLocation.empty())
            return;
            
        // 위로
        int i = 1, j = 0;
        while(1)
        {
            if(iLocation[j] - i >= 0)
            {
                matrix[iLocation[j] - i][jLocation[j]] = 0;   
                i++;
            }
            else
            {
                j++;
                i = 1;
            }
            
            if(j == iLocation.size())
                break;
        }

        // 아래로
        i = 1; j = 0;
        while(1)
        {
            if(iLocation[j] + i < matrix.size())
            {
                matrix[iLocation[j] + i][jLocation[j]] = 0;
                i++;
            }
            else
            {
                j++;
                i = 1;
            }
            
            if(j == iLocation.size())
                break;
        }

        // 좌로
        i = 1; j = 0;
        while(1)
        {
            if(jLocation[j] - i >= 0)
            {
                matrix[iLocation[j]][jLocation[j] - i] = 0;
                i++;
            }
            else
            {
                j++;
                i = 1;
            }
            
            if(j == jLocation.size())
                break;
        }

        // 우로
        i = 1; j = 0;
        while(1)
        {
            if(jLocation[j] + i < matrix[0].size())
            {
                matrix[iLocation[j]][jLocation[j] + i] = 0;
                i++;
            }
            else
            {
                j++;
                i = 1;
            }
            
            if(j == jLocation.size())
                break;
        }
       

    }
};
