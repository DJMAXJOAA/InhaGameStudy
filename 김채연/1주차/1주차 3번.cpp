// bfs:Ʈ���� �������� ���ٸ� �� ����(level)�� �湮�� ������ ���� ������ ��带 �湮�ϸ�, 
// �׷��� �������� ���ٸ� ������κ��� ���� ������ ���� ������� �켱 �湮�ϴ� ���̴�.
//You must do it in place. ->���ο� ������� ������ ����.
//-231 <= matrix[i][j] <= 231 - 1 ��� ���ڸ� �� ���ٴ� ��.

class Solution {
public:
    void fillrow(vector<vector<int>>& matrix, int row, int col) 
    {
        for (int i = 0; i < col; ++i) {
            matrix[row][i] = 0;
        }
    }
    void fillcol(vector<vector<int>>& matrix, int row, int col) 
    {
        for (int i = 0; i < row; ++i)
            matrix[i][col] = 0;
    }

    void setZeroes(vector<vector<int>>& matrix) 
    {
        int rowsize = matrix.size();
        int colsize = matrix[0].size();

        bool row[201]; //1 <= m, n <= 200
        bool col[201];
        queue<pair<int, int>> q; // == q.push(pair<int,int>(r,c))
        memset(row, false, sizeof(row)); // row,col�� false�� �ʱ�ȭ.
        memset(col, false, sizeof(col));

        //*���鼭 0�� ���� queue�� ����.
        for (int i = 0; i < rowsize; ++i) {
            for (int j = 0; j < colsize; ++j) {
                if (matrix[i][j] == 0) {
                    q.push(make_pair(i, j));
                }
            }
        }

        while (!q.empty()) {
            int x = q.front().first;
            int y = q.front().second;
            q.pop(); 
            if (row[x] == false) {
                fillrow(matrix, x, colsize); //x�� 0����.
                row[x] = true;
            }
            if (col[y] == false) {
                fillcol(matrix, rowsize, y); //[i][y] 0����.
                col[y] = true;
            }
        }
    }
};