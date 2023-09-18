class Solution {
public:
    bool vis[10][10];

    bool dfs(vector<vector<char>>& board, string& word, int depth, int i, int j) {
        if(depth == word.size()) {
            return true;
        }

        if(i < 0 || j < 0 || i >= board.size() || j >= board[0].size()) return false;
        if(board[i][j] != word[depth]) return false;
        if(vis[i][j]) return false;
        
        vis[i][j] = 1;

        bool top = dfs(board, word, depth+1, i-1, j);
        bool bottom = dfs(board, word, depth+1, i+1, j);
        bool left = dfs(board, word, depth+1, i, j-1);
        bool right = dfs(board, word, depth+1, i, j+1);

        vis[i][j] = 0;

        return top | bottom | left | right;
    }

    bool exist(vector<vector<char>>& board, string word) {
        int row = board.size();
        int col = board[0].size();
        for(int i=0; i<10; i++) fill(vis[i], vis[i]+10, 0);
        
        for(int i=0; i<row; i++) {
            for(int j=0; j<col; j++) {
                if(board[i][j] == word[0])
                {
                    if(dfs(board, word, 0, i, j)) return true;
                }
            }
        }

        return false;
    }
};