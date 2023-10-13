class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.size();
        vector<bool> dp(n+1, false);
        dp[n] = true;

        for(int i = n-1; i>=0;i--)
        {
            for(auto x : wordDict)
            {
                if(i + x.size() <= s.size() && s.substr(i,x.size()) == x)
                {
                    dp[i] = dp[i + x.size()];
                }
                if(dp[i] == true)break;
            }
        }
        return dp[0];
    }
};