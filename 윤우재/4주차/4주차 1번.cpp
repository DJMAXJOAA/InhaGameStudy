class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix)
    {
        vector<int> answer;
        vector<vector<int>> visited(matrix.size(), vector<int>(matrix[0].size(), 0));
        //우하좌상
        int xDir[4] = { 1,0,-1,0 };
        int yDir[4] = { 0,1,0,-1 };

        int totalCnt = matrix.size() * matrix[0].size();
        int cnt = 0;


        int dirIdx = 0;
        int x = 0; int y = 0;
        while (cnt < totalCnt)
        {
            //일단 추가하고, 카운트 늘리고, 방문처리
            answer.push_back(matrix[y][x]);
            cnt++;
            visited[y][x] = 1;
            //다음 위치가 배열 밖이거나, 방문처리된 곳이라면 dir바꾸기
            if (x + xDir[dirIdx] >= matrix[0].size() || x + xDir[dirIdx] < 0 ||
                y + yDir[dirIdx] >= matrix.size() || y + yDir[dirIdx] < 0 ||
                visited[y + yDir[dirIdx]][x + xDir[dirIdx]])
                dirIdx = (dirIdx + 1) % 4;
            y += yDir[dirIdx];
            x += xDir[dirIdx];
        }
        return answer;
    }

};