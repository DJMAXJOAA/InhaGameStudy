[8���� 4��] / Word Search / 52�� / https://leetcode.com/problems/word-search/

[���� ����]
��� �˰��� = ��Ʈ��ŷ, DFS
1. ���ڿ��� ũ��� ���� �ε����� ��ġ�� ������ Ž��
2. ��Ʈ��ŷ�� ���ؼ� �湮 ���¸� ���ڿ��� ǥ�� (2���� �迭�� �ص� ����)

[������]
1. ��Ʈ��ŷ �ҰŸ� BFS�� �����ϸ� ���� ����(�����ؾ��� ��ҵ� ����, ��� ���� üũ�ϰ� �Ǵϱ� �ð��� �ξ� �����ɸ�)
2. DFS�� Ư�� ������ ���� Ž��(��Ʈ��ŷ)�� �����ϰ�, BFS�� ��� �湮ó���̳� �ִܰ�ο� ���� (�Ѵ� ���� �����ѵ�, Ưȭ�� �κ��� �ٸ�)

[�ٸ� Ǯ�� ���]
1. BFS (��� ��츦 �� ���ϴϱ� ��Ǯ��)
2. DP (�����ؾ��� ��ҵ��� ���� -> 3���� �迭�̶� �� �Ⱦ��°� ����)
3. Ʈ���� (���ڿ� �˻� Ʈ�� -> ���� �ܾ �˻��� �� Ưȭ�� �˰����̶�, ���� ���� �� �ʿ䰡 ����)
4. A* (������ ������ �޸���ƽ ���� �����ϱ� �ָ��ϴ�)

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