class Solution
{
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights)
    {
        //BFS

        vector<vector<int>> ans;
        int m = heights.size();
        int n = heights[0].size();

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                bool PO = false;
                bool AO = false;
                bool visited[m][n];
                fill(&visited[0][0], &visited[m - 1][n], false);
                //vector<vector<bool>> visited(m, vector<bool>(n, false)); //ChatGPT -> RuntimeError
                queue<pair<int, int>> que;
                visited[i][j] = true;
                que.push(make_pair(i, j));

                while (!que.empty())
                {
                    pair<int, int> temp = que.front();
                    que.pop();

                    if (temp.first - 1 < 0) PO = true;
                    else
                    {
                        if (!visited[temp.first - 1][temp.second] &&
                            heights[temp.first - 1][temp.second] <= heights[temp.first][temp.second])
                        {
                            visited[temp.first - 1][temp.second] = true;
                            que.push(make_pair(temp.first - 1, temp.second));
                        }
                    }

                    if (temp.second - 1 < 0) PO = true;
                    else
                    {
                        if (!visited[temp.first][temp.second - 1] &&
                            heights[temp.first][temp.second - 1] <= heights[temp.first][temp.second])
                        {
                            visited[temp.first][temp.second - 1] = true;
                            que.push(make_pair(temp.first, temp.second - 1));
                        }
                    }

                    if (temp.first + 1 >= m) AO = true;
                    else
                    {
                        if (!visited[temp.first + 1][temp.second] &&
                            heights[temp.first + 1][temp.second] <= heights[temp.first][temp.second])
                        {
                            visited[temp.first + 1][temp.second] = true;
                            que.push(make_pair(temp.first + 1, temp.second));
                        }
                    }

                    if (temp.second + 1 >= n) AO = true;
                    else
                    {
                        if (!visited[temp.first][temp.second + 1] &&
                            heights[temp.first][temp.second + 1] <= heights[temp.first][temp.second])
                        {
                            visited[temp.first][temp.second + 1] = true;
                            que.push(make_pair(temp.first, temp.second + 1));
                        }
                    }

                }

                if (PO && AO)
                {
                    vector<int> temp = { i,j };
                    ans.push_back(temp);
                }

            }
        }

        return ans;

    }

};