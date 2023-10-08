
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int len = s.length();
        vector<vector<bool>> is_contain(len, vector<bool>(len, false));

        string word;
        int find_pos;
        for (int i = 0; i < wordDict.size(); ++i) {
            word = wordDict[i];
            int start_pos = 0, word_len = word.length(), end_pos;
            while (start_pos < len) {
                find_pos = s.find(word, start_pos);
                if (find_pos == string::npos)
                    break;  //문자열이 없는 경우

                end_pos = find_pos + word_len;
                is_contain[find_pos][end_pos - 1] = true;
                start_pos = find_pos + 1;
            }
        }

        vector<bool> is_connect(len + 1, false);
        is_connect[len] = true;
        for (int i = len - 1; i >= 0; --i)
            for (int j = i; j < len; ++j)
                if (is_contain[i][j] && is_connect[j + 1]) {
                    is_connect[i] = true;
                    break;
                }

        return is_connect[0];
    }
};