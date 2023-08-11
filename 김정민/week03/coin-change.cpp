// https://leetcode.com/problems/coin-change/

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int MX = 9999999;
        int dp[100005];
        fill(dp, dp+100005, MX);
        dp[0] = 0;
        
        int sz = (int)coins.size();
        for(int i=0; i<sz; i++)
        {
            int cur = coins[i];
            if(cur > amount) continue;

            for(int j=cur; j<=amount; j++)
            {
                dp[j] = min(dp[j], dp[j-cur] + 1);
                if(j % cur == 0)
                {
                    dp[j] = min(dp[j], j / cur);
                }
            }
        }

        if(dp[amount] == MX) return -1;
        return dp[amount];
    }
};