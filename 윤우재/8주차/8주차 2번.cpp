class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int rows = grid.size();
        if (rows == 0) return 0;

        int cols = grid[0].size();
        int cnt = 0;

        vector<vector<bool>> visited(rows, vector<bool>(cols, false));

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (!visited[i][j] && grid[i][j] == '1') {
                    cnt++;
                    bfs(grid, visited, i, j);
                }
            }
        }
        return cnt;
    }

    void bfs(vector<vector<char>>& grid, vector<vector<bool>>& visited, int i, int j) {
        int xDir[4] = { 0, 0, -1, 1 };
        int yDir[4] = { -1, 1, 0, 0 };

        //재귀호출 bfs 쓰면 메모리 터지니까 queue쓰기
        queue<pair<int, int>> q;
        q.push({ i, j });
        visited[i][j] = true;

        while (!q.empty()) {
            pair<int, int> curr = q.front();
            q.pop();

            for (int a = 0; a < 4; a++) {
                int ni = curr.first + yDir[a];
                int nj = curr.second + xDir[a];

                if (ni >= 0 && ni < grid.size() && nj >= 0 && nj < grid[0].size() && grid[ni][nj] == '1' && !visited[ni][nj]) {
                    q.push({ ni, nj });
                    visited[ni][nj] = true;
                }
            }
        }
    }
};