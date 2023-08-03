class Solution {
public:
    int maxProfit(vector<int>& prices) {
        vector<int> dp(prices.size());
        dp[0] = 0;
        int min = prices[0];
        for(int i = 1; i<prices.size();i++)
        {
            if(prices[i-1]<min)min=prices[i-1];
            dp[i] = dp[i-1]>(prices[i]-min) ? dp[i-1] : (prices[i]-min); 
        }
        return dp[prices.size()-1];
    }
};