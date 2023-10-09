class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        
        unordered_map<string, vector<string>> map;
        
        for(int i = 0; i < strs.size(); i++ )
        {
            string word = strs[i];
            sort(word.begin(), word.end());
            map[word].push_back(strs[i]);
        }
        
        vector<vector<string>> answer;
        for(pair<string, vector<string>> temp : map)
        {
            answer.push_back(temp.second);
        }

        return answer;
    }
};
