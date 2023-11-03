class Solution {
public:
    int dp[101];

    int dfs(string& s, int idx) {
        if(idx > s.size()) {
            return dp[idx] = 0;
        }

        if(idx == s.size()) {
            dp[idx] = 1;
            return dp[idx];
        }

        if(dp[idx] != -1) return dp[idx];

        dp[idx] = 0;
        string s1 = s.substr(idx, 1);
        string s2 = "";
        if(idx+2 <= s.size()) s2 = s.substr(idx, 2);

        if(s1 != "0")
            dp[idx] += dfs(s, idx+1);

        if(!s2.empty()) {
            if(s2[0] != '0') {
                int num = stoi(s2);
                if((10 <= num && num <= 19) || (20 <= num && num <= 26)) dp[idx] += dfs(s, idx+2);
            }
        }        

        return dp[idx];        
    }

    int numDecodings(string s) {   
        fill(dp, dp+101, -1);

        dfs(s, 0);

        return dp[0];
    }
};