/*
    DFS
    Runtime: 27 ms (78.29%)
    Memory: 12.69 MB (57.32%)
*/

class Solution {
public:
    void DFS(vector<vector<char>>& grid, int y, int x)
    {
        if (y < 0 || y >= grid.size() || x < 0 || x >= grid[0].size())
        {
            return;
        }

        if (grid[y][x] == '2' || grid[y][x] == '0')
            return;

        grid[y][x] = '2';
        DFS(grid, y + 1, x);
        DFS(grid, y, x - 1);
        DFS(grid, y - 1, x);
        DFS(grid, y, x + 1);
    }

    int numIslands(vector<vector<char>>& grid) {
        int height = grid.size();
        int width = grid[0].size();
        int result = 0;

        for (int i = 0; i < height; i++)
        {
            for (int j = 0; j < width; j++)
            {
                if (grid[i][j] == '1')
                {
                    DFS(grid, i, j);
                    result++;
                }
            }
        }

        return result;
    }
};

/*
    BFS
    Runtime: 32 ms (48.86%)
    Memory: 18.5 MB (27.64%)
*/

class Solution {
public:
    int dx[4] = { -1, 0, 1, 0 }, dy[4] = { 0, -1, 0, 1 };

    void BFS(vector<vector<char>>& grid, int height, int width, int y, int x)
    {
        queue<pair<int, int>> q;
        q.push({ y, x });
        grid[y][x] = '0';

        while (!q.empty())
        {
            int cur_y = q.front().first;
            int cur_x = q.front().second;
            q.pop();

            for (int i = 0; i < 4; i++)
            {
                int ny = cur_y + dy[i];
                int nx = cur_x + dx[i];
                if (((0 <= ny && ny < height) && (0 <= nx && nx < width)) && grid[ny][nx] == '1')
                {
                    q.push({ ny, nx });
                    grid[ny][nx] = '2';
                }
            }
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        int height = grid.size();
        int width = grid[0].size();
        int result = 0;

        for (int i = 0; i < height; i++)
        {
            for (int j = 0; j < width; j++)
            {
                if (grid[i][j] == '1')
                {
                    BFS(grid, height, width, i, j);
                    result++;
                }
            }
        }

        return result;
    }
};