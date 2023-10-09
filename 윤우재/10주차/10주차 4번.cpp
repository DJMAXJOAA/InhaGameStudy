class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) 
    {
        map<string, vector<string>> map;
        vector<vector<string>> answer;
        for(string str : strs)
        {
            string sortedStr = str;
            sort(sortedStr.begin(), sortedStr.end());
            map[sortedStr].push_back(str);
        }
        for(auto e : map)
        {
            answer.push_back(e.second);
        }
        return answer;
    }
};