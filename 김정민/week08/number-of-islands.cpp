class Solution {
public:
    int dx[4] = {-1, 0, 1, 0};
    int dy[4] = {0, 1, 0, -1};

    int numIslands(vector<vector<char>>& grid) {
        bool vis[301][301];
        for(int i=0; i<301; i++) fill(vis[i], vis[i]+301, 0);

        int row = grid.size();
        int col = grid[0].size();
        int ans = 0;

        for(int i=0; i<row; i++)
        {
            for(int j=0; j<col; j++)
            {
                if(grid[i][j] == '1' && vis[i][j] == 0)
                {
                    ans++;            
                    queue<pair<int, int>> Q;
                    Q.push({i, j});

                    while(!Q.empty())
                    {
                        auto cur = Q.front(); Q.pop();

                        for(int d=0; d<4; d++)
                        {
                            int nx = cur.first + dx[d];
                            int ny = cur.second + dy[d];

                            if(nx < 0 || ny < 0 || nx >= row || ny >= col) continue;
                            if(grid[nx][ny] == '0') continue;
                            if(vis[nx][ny]) continue;

                            vis[nx][ny] = 1;
                            Q.push({nx, ny});
                        }
                    }
                }
            }
        }

        return ans;
    }
};
