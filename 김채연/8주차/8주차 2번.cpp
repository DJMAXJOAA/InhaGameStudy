// Number of Islands
// 섬의 개수 구하기, 1은 땅, 0은 물
// 상하좌우가 물이면 섬. 대각선은 x

class Solution {
public:
    int r_length = 0;
    int c_length = 0;

    int numIslands(vector<vector<char>>& grid) {
        r_length = grid.size();

        if (grid.size() == 0)
            return 0;
        c_length = grid[0].size();

        int cnt = 0;
        for (int i = 0; i < r_length; i++) {
            for (int j = 0; j < c_length; j++) {
                if (grid[i][j] == '1') {
                    cnt++;
                    findOne(grid, i, j);
                }
            }
        }

        return cnt;
    }

    void findOne(vector<vector<char>>& grid, int r, int c) {
        if (r < 0 || r >= r_length || c < 0 || c >= c_length)
            return;

        if (grid[r][c] == '0')
            return;

        grid[r][c] = '0';

        findOne(grid, r, c - 1);
        findOne(grid, r, c + 1);
        findOne(grid, r - 1, c);
        findOne(grid, r + 1, c);

        return;
    }

};