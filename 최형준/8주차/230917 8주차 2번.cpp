[8���� 2��] / Number of Islands / 20�� / https://leetcode.com/problems/number-of-islands/

[���� ����]
��� �˰��� = BFS
1. �����¿� ��ĭ�� Ž���� �迭 dx, dy ����
2. ���¸� üũ�س��� island 2���� �迭 ����
3. ���� ���¸� bfs�� üũ�ؼ� island�� ���

[������]
ũ�� ���µ�?

[�ٸ� Ǯ�� ���]
1. DFS

Time taken : 20 m 24 s
Runtime 32ms
Beats 49.90 % of users with C++
Memory 19.45MB
Beats 15.10 % of users with C++

class Solution {
public:
    vector<int> dx = { -1, 1, 0, 0 };
    vector<int> dy = { 0, 0, -1, 1 };

    void bfs(int x, int y, vector<vector<char>>& grid, vector<vector<int>>& island)
    {
        int grid_x = grid[0].size();
        int grid_y = grid.size();

        queue<pair<int, int>> q;

        island[y][x] = 1;
        q.push(make_pair(x, y));

        while (!q.empty())
        {
            int current_x = q.front().first;
            int current_y = q.front().second;
            q.pop();

            for (int i = 0; i < 4; i++)
            {
                int check_x = current_x + dx[i];
                int check_y = current_y + dy[i];

                if ((check_x >= 0 && check_x < grid_x) && (check_y >= 0 && check_y < grid_y))
                {
                    if (grid[check_y][check_x] == '1' && island[check_y][check_x] == 0)
                    {
                        q.push(make_pair(check_x, check_y));
                        island[check_y][check_x] = 1;
                    }
                }
            }
        }
    }

    int numIslands(vector<vector<char>>& grid)
    {
        int result = 0;
        vector<vector<int>> island(grid.size(), vector<int>(grid[0].size(), 0));

        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid[i].size(); j++)
            {
                if (grid[i][j] == '1' && island[i][j] == 0)
                {
                    result++;
                    bfs(j, i, grid, island);
                }
            }
        }

        return result;
    }
};

[�ٸ� Ǯ�� ���]
1. DFS

void dfs(vector<vector<char>>& grid, int i, int j) {
    if (i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size() || grid[i][j] == '0')
        return;

    grid[i][j] = '0';  // Mark as visited

    dfs(grid, i + 1, j);
    dfs(grid, i - 1, j);
    dfs(grid, i, j + 1);
    dfs(grid, i, j - 1);
}

int numIslands(vector<vector<char>>& grid) {
    int count = 0;
    for (int i = 0; i < grid.size(); i++) {
        for (int j = 0; j < grid[0].size(); j++) {
            if (grid[i][j] == '1') {
                dfs(grid, i, j);
                count++;
            }
        }
    }
    return count;
}