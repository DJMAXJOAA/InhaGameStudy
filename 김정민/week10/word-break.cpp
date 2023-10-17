class Solution {
public:
    set<string> S;
    int dp[301];

    bool dfs(string s, int st) {
        if(st >= s.size()) return true;

        if(dp[st] != -1) return dp[st];
        
        for(int i=st+1; i<=s.size(); i++) {
            string tmp = s.substr(st, i - st);
    
            if(S.count(tmp) && dfs(s, i)) {
                dp[st] = 1;
                return dp[st];
            }
        }

        return dp[st] = 0;
    }

    bool wordBreak(string s, vector<string>& wordDict) {
        for(auto& s : wordDict) S.insert(s);
        fill(dp, dp+301, -1);
        return dfs(s, 0);
    }
};
