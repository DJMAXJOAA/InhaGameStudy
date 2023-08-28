// https://leetcode.com/problems/pacific-atlantic-water-flow/

class Solution {
public:
    bool pacific[201][201];
    bool atlantic[201][201];

    void bfs(vector<vector<int>>& board, int x, int y, bool isPacific)
    {
        queue<pair<int, int>> Q;
        Q.push({x, y});

        int row = board.size();
        int col = board[0].size();

        vector<vector<bool>> vis(row, vector<bool>(col, false));
        vis[x][y] = true;

        int dx[4] = {-1, 0, 1, 0};
        int dy[4] = {0, -1, 0, 1};
        if(isPacific)
        {
            pacific[x][y] = 1;
        }
        else
        {
            atlantic[x][y] = 1;
        }
        while(!Q.empty())
        {
            auto cur = Q.front(); Q.pop();

            for(int dir=0; dir<4; dir++)
            {
                int nx = cur.first + dx[dir];
                int ny = cur.second + dy[dir];

                if(nx < 0 || nx >= row || ny < 0 || ny >= col) continue;
                if(vis[nx][ny]) continue;
                if(board[nx][ny] < board[cur.first][cur.second]) continue;

                Q.push({nx, ny});
                vis[nx][ny] = 1;
                
                if(isPacific)
                {
                    pacific[nx][ny] = 1;
                }
                else
                {
                    atlantic[nx][ny] = 1;
                }
            }
        }
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int row = heights.size();
        int col = heights[0].size();
        vector<vector<int>> ans;

        for(int i=0; i<row; i++)
        {
            fill(pacific[i], pacific[i]+col, 0);
            fill(atlantic[i], atlantic[i]+col, 0);
        }

        // pacific
        for(int i=0; i<row; i++)
        {
            bfs(heights, i, 0, true);
        }
        for(int i=0; i<col; i++)
        {
            bfs(heights, 0, i, true);
        }

        // atlantic
        for(int i=0; i<row; i++)
        {
            bfs(heights, i, col-1, false);
        }
        for(int i=0; i<col; i++)
        {
            bfs(heights, row-1, i, false);
        }

        for(int i=0; i<row; i++)
        {
            for(int j=0; j<col; j++)
            {
                if(pacific[i][j] && atlantic[i][j])
                {
                    vector<int> tmp{i, j};
                    ans.push_back(tmp);
                }
            }
        }

        return ans;
    }
};
