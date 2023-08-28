class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        
        vector<vector<int>> answer;
        int ROW = heights.size();
        int COL = heights[0].size();
        
        vector<vector<bool>> pacific(ROW, vector<bool>(COL));
        vector<vector<bool>> atlantic(ROW, vector<bool>(COL));
        
        for (int i = 0; i < ROW; i++) 
        {
            dfs(heights, pacific, i, 0);
            dfs(heights, atlantic, i, COL-1);
        }
        
        for (int j = 0; j < COL; j++) {
            
            dfs(heights, pacific, 0, j);
            dfs(heights, atlantic, ROW-1, j);
        }
        
        for (int i = 0; i < ROW; i++) 
        {
            for (int j = 0; j < COL; j++) 
            {
                if (pacific[i][j] && atlantic[i][j]) 
                    answer.push_back({i,j});       
            }
        }
        return answer;
    }

   void dfs(vector<vector<int>>& h, vector<vector<bool>>& vis, int i, int j) {
        
        int m = h.size();
        int n = h[0].size();

        vis[i][j] = true;
        // 경계선 && 가본적이 없어야함 && 움직인 곳의 값이 더크면  --> 다시 탐색
        //up
        if (i-1 >= 0 && vis[i-1][j] != true && h[i-1][j] >= h[i][j])
            dfs(h, vis, i-1, j);
        //down
        if (i+1 < m && vis[i+1][j] != true && h[i+1][j] >= h[i][j])
            dfs(h, vis, i+1, j);
        //left
        if (j-1 >= 0 && vis[i][j-1] != true && h[i][j-1] >= h[i][j])
            dfs(h, vis, i, j-1);
        //right
        if (j+1 < n && vis[i][j+1] != true && h[i][j+1] >= h[i][j])
            dfs(h, vis, i, j+1);
    }
};
