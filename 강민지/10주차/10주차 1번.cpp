class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {

        unordered_map<string, int> map;

        // map: <key, value>
        for(int i = 0; i < wordDict.size(); i++)
            map.insert({wordDict[i], i});
        
        int sSize = s.size();

        vector<bool> dp(sSize+1);
        dp[0] = true;

        for(int i = 1; i <= sSize; i++)
        {
            for(int j = 0; j < i; j++)
            {
                // map.count -> key가 포함되면 1 아니면 0을 반환
                if(dp[j] && map.count(s.substr(j, i-j)))
                    dp[i] = true;
            }
        }

        return dp[sSize];
    }
};
