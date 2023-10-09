class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> map;
        vector<vector<string>> answer;
        int idx = 0;
        for (string s : strs) {
            sort(s.begin(), s.end());
            map[s].push_back(strs[idx]);
            idx++;
        }
        for (auto m : map) {
            answer.push_back(m.second);
        }
        return answer;
    }
};