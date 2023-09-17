[8주차 4번] / Word Search / 52분 / https://leetcode.com/problems/word-search/

[문제 접근]
사용 알고리즘 = 백트래킹, DFS
1. 문자열의 크기와 현재 인덱스가 일치할 때까지 탐색
2. 백트래킹을 위해서 방문 상태를 문자열로 표현 (2차원 배열로 해도 가능)

[개선점]
1. 백트래킹 할거면 BFS는 웬만하면 쓰지 말자(저장해야할 요소도 많고, 모든 곳을 체크하게 되니까 시간도 훨씬 오래걸림)
2. DFS는 특정 순서에 따른 탐색(백트래킹)에 적합하고, BFS는 노드 방문처리이나 최단경로에 적합 (둘다 서로 가능한데, 특화된 부분이 다름)

[다른 풀이 방법]
1. BFS (모든 경우를 다 비교하니까 안풀림)
2. DP (저장해야할 요소들이 많음 -> 3차원 배열이라 걍 안쓰는게 나음)
3. 트라이 (문자열 검색 트리 -> 여러 단어를 검색할 때 특화된 알고리즘이라, 굳이 적용 할 필요가 없음)
4. A* (가능은 하지만 휴리스틱 값을 설정하기 애매하다)

Time taken : 52 m 45 s
Runtime 394ms
Beats 68.57 % of users with C++
Memory 8.32MB
Beats 9.72 % of users with C++

class Solution {
public:
    vector<int> dx = { -1, 1, 0, 0 };
    vector<int> dy = { 0, 0, -1, 1 };

    bool dfs(int x, int y, vector<vector<char>>& board, string& word, int index)
    {
        if (index == word.size()) return true;

        if (x < 0 || y < 0 || x >= board[0].size() || y >= board.size() || board[y][x] != word[index])
            return false;

        char tmp = board[y][x];
        board[y][x] = '#';

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (dfs(nx, ny, board, word, index + 1))
                return true;
        }

        board[y][x] = tmp;

        return false;
    }

    bool bfs(int x, int y, vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();

        queue<tuple<int, int, int, vector<vector<bool>>>> q;
        vector<vector<bool>> initialVisited(m, vector<bool>(n, false));
        initialVisited[y][x] = true;

        q.push(make_tuple(y, x, 1, initialVisited));

        while (!q.empty()) {
            int current_x, current_y, index;
            vector<vector<bool>> visited;

            tie(current_y, current_x, index, visited) = q.front();
            q.pop();

            if (index == word.size())
                return true;

            for (int i = 0; i < 4; i++) {
                int check_x = current_x + dx[i];
                int check_y = current_y + dy[i];

                if (check_x >= 0 && check_x < n && check_y >= 0 && check_y < m &&
                    !visited[check_y][check_x] &&
                    board[check_y][check_x] == word[index])
                {
                    cout << check_x << " " << check_y << "\n";
                    vector<vector<bool>> newVisited = visited;
                    newVisited[check_y][check_x] = true;
                    q.push(make_tuple(check_y, check_x, index + 1, newVisited));
                }
            }
        }

        return false;
    }

    bool exist(vector<vector<char>>& board, string word)
    {
        for (int i = 0; i < board.size(); i++)
        {
            for (int j = 0; j < board[i].size(); j++)
            {
                if (board[i][j] == word[0] && dfs(j, i, board, word, 0))
                {
                    return true;
                }
            }
        }
        return false;
    }
};