// bfs:트리를 기준으로 본다면 한 수준(level)의 방문이 끝나야 다음 수준의 노드를 방문하며, 
// 그래프 기준으로 본다면 출발지로부터 간선 개수가 적은 노드들부터 우선 방문하는 것이다.
//You must do it in place. ->새로운 저장공간 만들지 말라.
//-231 <= matrix[i][j] <= 231 - 1 모든 숫자를 다 쓴다는 말.

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
        memset(row, false, sizeof(row)); // row,col을 false로 초기화.
        memset(col, false, sizeof(col));

        //*돌면서 0인 값은 queue에 넣음.
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
                fillrow(matrix, x, colsize); //x열 0으로.
                row[x] = true;
            }
            if (col[y] == false) {
                fillcol(matrix, rowsize, y); //[i][y] 0으로.
                col[y] = true;
            }
        }
    }
};