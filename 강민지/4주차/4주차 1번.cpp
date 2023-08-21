class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        
        vector<int> answer;
        vector<int> temp(matrix[0].size(), 0);
        vector<vector<int>> isGone(matrix.size(), temp);
        int i = 0, j = 0;
        int minCol = 0, minRow = 0;
        int maxCol = matrix[0].size();
        int maxRow = matrix.size();

        while(1)
        {
            j = minRow;
            // 열 증가 →
            for(i = minCol; i < maxCol; i++)
            {
                if(isGone[j][i] == 1)   
                    continue;
                
                answer.push_back(matrix[j][i]);
                isGone[j][i] = 1;
            }
            i--;
            // 행 증가 ↓
            for(j = minRow; j < maxRow; j++)
            {
                if(isGone[j][i] == 1)   
                    continue;
                
                answer.push_back(matrix[j][i]);
                isGone[j][i] = 1;
            }
            j--;
            // 열 감소 ←
            for(i = maxCol - 1; i >= minCol; i--)
            {
                if(isGone[j][i] == 1)   
                    continue;

                answer.push_back(matrix[j][i]);
                isGone[j][i] = 1;
            }
            i++;
            // 행 감소 ↑
            for(j = maxRow - 1; j >= minRow; j--)
            {
                if(isGone[j][i] == 1)   
                    continue;

                answer.push_back(matrix[j][i]);
                isGone[j][i] = 1;
            }
            j++;

            maxRow--;
            maxCol--;
            minRow++;
            minCol++;

            if(answer.size() == (matrix[0].size() * matrix.size()))  break;
        }
        
        return answer;
    }
};
