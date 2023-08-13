class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        
        int dp[amount+1];
        dp[0] = 0;
        
        sort(begin(coins), end(coins));

        for(int i = 1; i <= amount; i++)
        {
            dp[i] = INT_MAX; 
            
            for(int c : coins) // coins에 있는 숫자만큼 떨어진 곳의 dp값과 비교
            {
                if(i - c < 0) break; // dp의 index 범위에서 벗어남
                if(dp[i-c] != INT_MAX)
                    dp[i] = min(dp[i], 1 + dp[i-c]);
            }
        }

        return dp[amount] == INT_MAX ? -1 : dp[amount];
    }
};

// 최대값으로 비교해서 찾았을 때 반례 
// coins = [186, 419, 83, 408], amount = 6249
// output = 20
