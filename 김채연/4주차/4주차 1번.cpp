// Q1. Spiral Matrix
// 문제 해석: 나선형 모양으로 방문 처리.

//좌표 이동을 위한
int dx[4] = { 0,1,0,-1 };
int dy[4] = { 1,0,-1,0 };
class Solution {
public:

    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        //row, col은 나중에도 쓰이므로 미리 변수에 넣어둡니다.
        int row = matrix.size();
        int col = matrix[0].size();
        //방문처리용 벡터
        vector<bool> v(col, false);
        vector<vector<bool>> vc;
        //결과값을 담을 벡터
        vector<int> res;

        //방문처리 벡터 초기화
        for (int i = 0; i < row; ++i)
            vc.push_back(v);

        //BFS를 이용할 것입니다.
        queue<pair<int, int>> q;
        q.push(make_pair(0, 0));
        vc[0][0] = true;
        //dis는 방향전환이 필요할 때 사용하는 변수입니다.
        int dis = 0;
        //row * col만큼 돌면 빠져나오기 위한 변수
        int count = 0;
        while (!q.empty()) {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            res.push_back(matrix[x][y]);
            ++count;
            if (count == row * col) break;

            int newX = x + dx[dis];
            int newY = y + dy[dis];

            //만약 새 좌표 값이 범위를 벗어나거나 이미 방문한 좌표를 지나려 한다면 좌표를 다시 갱신해줍니다.
            if (newX < 0 || newX >= matrix.size() || newY < 0 || newY >= matrix[0].size() || vc[newX][newY]) {
                dis = (dis + 1) % 4;
                newX = x + dx[dis];
                newY = y + dy[dis];
            }
            if (!vc[newX][newY]) {
                q.push(make_pair(newX, newY));
                vc[newX][newY] = true;
            }
        }

        return res;
    }
};