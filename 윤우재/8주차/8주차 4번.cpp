class Solution {
    bool flag = false;
public:
    bool exist(vector<vector<char>>& board, string word) {

        for(int i = 0; i<board.size();i++)
        {
            for(int j = 0; j<board[0].size();j++)
            {
                if(word[0] == board[i][j])
                {
                    dfs(board,word, i,j,0);
                    if(flag)return true;
                }
            }
        }
        return false;
    }

    void dfs(vector<vector<char>>& board, string word, int i, int j, int idx)
    {
        if(idx == word.size()) flag = true;
        if( i< 0 || j < 0 || i > board.size() -1 || j > board[0].size() -1 || board[i][j] != word[idx]) return;
        
        char curChar = board[i][j];
        board[i][j] = ' ';
        int xDir[4] = { 0, 0, -1, 1 };
        int yDir[4] = { -1, 1, 0, 0 };
        for(int a = 0; a<4;a++)
        {
            dfs(board,  word, i+yDir[a],j+xDir[a],idx+1);
        }
        board[i][j] = curChar;
    }
    
};