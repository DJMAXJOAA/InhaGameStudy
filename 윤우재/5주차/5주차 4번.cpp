class Solution {
public:
    void dfs(vector<vector<int>>& heights, vector<vector<bool>>& visited, 
    int i, int j, int prevHeight, bool isPacific, bool isAtlantic)
    {
        if(i<0||i>=heights.size() || j<0||j>=heights[0].size())return;
        if(visited[i][j]||heights[i][j]<prevHeight)return;

        visited[i][j] = true;

        if(isPacific && isAtlantic) return;

        //상하좌우
        dfs(heights, visited, i - 1, j, heights[i][j], isPacific, isAtlantic);
        dfs(heights, visited, i + 1, j, heights[i][j], isPacific, isAtlantic);
        dfs(heights, visited, i, j - 1, heights[i][j], isPacific, isAtlantic);
        dfs(heights, visited, i, j + 1, heights[i][j], isPacific, isAtlantic);
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) 
    {
        if(heights.empty() || heights[0].empty()) return {};
        vector<vector<int>> answer;

        int row = heights.size();
        int col = heights[0].size();

        vector<vector<bool>> pacific(row,vector<bool>(col,false));
        vector<vector<bool>> atlantic(row,vector<bool>(col,false));

        for(int i = 0; i<row;i++)
        {
            dfs(heights,pacific,i,0,INT_MIN,true,false);
            dfs(heights,atlantic,i,col-1,INT_MIN,false, true);
            
        }
        
        for(int j = 0; j<col;j++)
        {
            dfs(heights,pacific,0,j,INT_MIN,true,false);
            dfs(heights,atlantic,row-1,j,INT_MIN,false, true);
            
        }
        
        for(int i = 0; i<row;i++)
            for(int j = 0; j<col;j++)
            {
                if(pacific[i][j]&&atlantic[i][j])
                    answer.push_back({i,j});
            }
        
        return answer;
    }
    
};