class Solution {
public:
    bool exist(vector<vector<char>>& board, string& word, int idx, int row, int col) {
        if (row < 0 || row >= board.size() ||
            col < 0 || col >= board[0].size() ||
            board[row][col] != word[idx])
        {
            return false;
        }


        if (idx + 1 == word.size()) return true;

        //replace to a special char to avoid duplication.
        board[row][col] = '\0';

        if (exist(board, word, idx + 1, row + 1, col) ||
            exist(board, word, idx + 1, row - 1, col) ||
            exist(board, word, idx + 1, row, col + 1) ||
            exist(board, word, idx + 1, row, col - 1))
        {
            return true;
        }

        //restore the char
        board[row][col] = word[idx];

        return false;
    }

    bool exist(vector<vector<char>>& board, string word) {
        //https://leetcode.com/problems/word-search/solutions/1908561/C++:-How-to-prune-the-DFS-to-0ms/

        if (board.size() <= 0 || word.size() <= 0) return false;

        int row = board.size();
        int col = board[0].size();

        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                if (board[i][j] == word[0])
                {
                    if (exist(board, word, 0, i, j))
                    {
                        return true;
                    }
                }
            }
        }

        return false;
    }
};