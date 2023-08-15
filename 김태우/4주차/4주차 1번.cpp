class Solution
{
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix)
    {
        vector<int> ans;
        int m = matrix.size();
        int n = matrix[0].size();
        bool temp[m][n];
        int a = 0;
        int b = 0;
        int t = 0;

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                temp[i][j] = false;
            }
        }

        while (t < m * n)
        {
            while (b < n)
            {
                if (temp[a][b] == false)
                {
                    ans.push_back(matrix[a][b]);
                    temp[a][b] = true;
                    t++;
                    b++;
                }

                else
                {
                    break;
                }
            }

            a++;
            b--;

            while (a < m)
            {
                if (temp[a][b] == false)
                {
                    ans.push_back(matrix[a][b]);
                    temp[a][b] = true;
                    t++;
                    a++;
                }

                else
                {
                    break;
                }
            }

            b--;
            a--;

            while (b >= 0)
            {
                if (temp[a][b] == false)
                {
                    ans.push_back(matrix[a][b]);
                    temp[a][b] = true;
                    t++;
                    b--;
                }
                else
                {
                    break;
                }
            }

            b++;
            a--;

            while (a >= 0)
            {
                if (temp[a][b] == false)
                {
                    ans.push_back(matrix[a][b]);
                    temp[a][b] = true;
                    t++;
                    a--;
                }
                else
                {
                    break;
                }
            }

            a++;
            b++;

        }
        return ans;
    }
};