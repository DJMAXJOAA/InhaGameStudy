class Trie {
public:
    string word;
    bool is_word = false;
    Trie* children[26] = { NULL };
};

class Solution {
private:
    Trie* root = NULL;

    void insert(string& s) {
        Trie* temp = root;
        for (auto& i : s) {
            int k = i - 'a';
            if (temp->children[k] == NULL) {
                temp->children[k] = new Trie;
            }
            temp = temp->children[k];
        }
        temp->word = s;
        temp->is_word = true;
    }

    void dfs(vector<vector<char>>& board, vector<string>& res, Trie* temp, int i, int j) {

        if (i < 0 || i >= board.size() || j < 0 || j >= board[0].size() || board[i][j] == '*' || !(temp->children[board[i][j] - 'a']))
            return;

        temp = temp->children[board[i][j] - 'a'];

        if (temp->is_word) {
            res.push_back(temp->word);
            temp->is_word = false;
        }

        char temp_char = board[i][j];
        board[i][j] = '*';

        dfs(board, res, temp, i + 1, j);
        dfs(board, res, temp, i, j + 1);
        dfs(board, res, temp, i - 1, j);
        dfs(board, res, temp, i, j - 1);

        board[i][j] = temp_char;

        return;
    }

public:
    Solution() {
        root = new Trie;
    }
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        for (auto& s : words)
            insert(s);
        vector<string>res;
        Trie* temp = root;

        for (int i = 0; i < board.size(); i++)
            for (int j = 0; j < board[0].size(); j++)
                dfs(board, res, temp, i, j);

        return res;
    }

    /*--------destructor not neccesary-----------
        ~Solution(){
            clear_nodes(root);
        }

        void clear_nodes(Trie* root) //
        {
            for(int i = 0; i<26; i++)
                if(root->children[i] != NULL)
                    clear_nodes(root->children[i]);
            delete root;
        }
    -------------------------------------------*/
};



//     int dy[4] = {-1, 0, 1, 0};
//     int dx[4] = {0, -1, 0, 1};
//     bool ans = false;

// public:
//     bool HasWord(vector<vector<char>>& board, string words, bool & visited[][],
//      int m, int n, int index)
//     {
//         if((words[index] != board[m][n]) return false;
//         if(index == words.size()-1) return true;

//         visited[m][n] = true;

//         for(int i = 0; i < 4; i++)
//         {
//             int y = temp.first + dy[i];
//             int x = temp.second + dx[i];

//             if(y<0 || x<0 || y>=m || x>=n) continue;
//             if(visited[y][x]) continue;
//             if(board[y][x] !=words[index+1]) continue;

//             ans = HasWord(board,words,y,x,index+1);
//             if(ans) return ans;
//         }

//         return ans;

//     }

//     vector<string> findWords(vector<vector<char>>& board, vector<string>& words) 
//     {
//         vector<string> ans;
//         bool visited[a][b];
//         memset(visited,false,sizeof(visited));

//         for(int i = 0; i < words.size(); i++)
//         {
//             if(HasWord(board,words[i],0,0,0))
//             {
//                 ans.push_back(words[i]);
//             }
//         }

//         return ans;
//     }

    // bool HasWord(vector<vector<char>>& board, string words)
    // {
    //     int m = board.size();
    //     int n = board[0].size();
    //     int index = 0;

    //     int dy[4] = {-1, 0, 1, 0};
    //     int dx[4] = {0, -1, 0, 1};

    //     for(int i = 0; i < m; i++)
    //     {
    //         for(int j = 0; j < n; j++)
    //         {
    //             if(words[index] !=board[i][j]) continue;

    //             queue<pair<int,int>> que;
    //             bool visited[m][n];
    //             memset(visited,false,sizeof(visited));

    //             que.push({i,j});
    //             visited[i][j] = true;

    //             while(!que.empty())
    //             {
    //                 pair<int, int> temp = que.front();
    //                 que.pop();

    //                 // if has Rank, Use DFS
    //                 index++;

    //                 for(int i = 0; i < 4; i++)
    //                 {
    //                     int y = temp.first + dy[i];
    //                     int x = temp.second + dx[i];

    //                     if(y<0 || x<0 || y>=m || x>=n) continue;
    //                     if(visited[y][x]) continue;
    //                     if(board[y][x] !=words[index]) 
    //                     {
    //                         continue;
    //                     }

    //                     que.push({y,x});
    //                     visited[y][x] = true;
    //                 }
    //             }

    //             if(words.size() == index) return true;
    //             else index = 0;
    //         }
    //     }

    //     return false;
    // }

    // vector<string> findWords(vector<vector<char>>& board, vector<string>& words) 
    // {
    //     vector<string> ans;

    //     for(int i = 0; i < words.size(); i++)
    //     {
    //         if(HasWord(board,words[i]))
    //         {
    //             ans.push_back(words[i]);
    //         }
    //     }

    //     return ans;
    // }