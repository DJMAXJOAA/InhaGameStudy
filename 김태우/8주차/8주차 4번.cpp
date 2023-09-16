class Solution
{
    int dx[4] = { -1,0,1,0 };
    int dy[4] = { 0,-1,0,1 };
    bool visited[6][6];
    bool ans = false;

public:
    void BackTracking(int index, int m, int n, vector<vector<char>>& board, string word)
    {
        if (index == word.size())
        {
            ans = true;
            return;
        }

        for (int i = 0; i < 4; i++)
        {
            int y = m + dy[i];
            int x = n + dx[i];

            if (y < 0 || y >= board.size() || x < 0 || x >= board[0].size()) continue;
            if (visited[y][x]) continue;
            if (board[y][x] == word[index])
            {
                visited[y][x] = true;
                BackTracking(index + 1, y, x, board, word);
            }
        }

        //if no root, go back
        visited[m][n] = false;

    }

    bool exist(vector<vector<char>>& board, string word)
    {
        int m = board.size();
        int n = board[0].size();
        fill(&visited[0][0], &visited[5][6], false);

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (board[i][j] == word[0])
                {
                    visited[i][j] = true;
                    BackTracking(1, i, j, board, word);
                    fill(&visited[0][0], &visited[5][6], false);
                }
            }
        }

        return ans;
    }
};