class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        
        for(int i = 0; i < board.size(); i++)
        {
            for(int j = 0; j < board[0].size(); j++)
            {
                if(dfs(board, word, i , j))
                    return true;
            }
        }

        return false;
    }


    bool dfs(vector<vector<char>>& board, string& word, int i, int j)
    {
        if(word.size() == 0)  // word의 끝에 도달할 때   
            return true;

        if(i < 0 || j < 0 || i >= board.size() || j >= board[0].size()) // 행열 범위를 벗어났을 때
            return false;
        if(board[i][j] != word[0]) // 탐색할 단어가 아닐 때
            return false;

        char c = board[i][j];
        board[i][j] = 'x'; // 방문한 곳임을 체크
        string s = word.substr(1); // 1번 인덱스부터 끝까지

        bool res = dfs(board, s, i+1, j) || dfs(board, s, i-1, j) || dfs(board, s, i, j-1) || dfs(board, s, i, j+1);

        board[i][j] = c;
        return res;
    }
        
};
