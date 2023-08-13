class Solution {
public:
	int coinChange(vector<int>& coins, int amount) {
		if (amount == 0)
		{
			return 0;
		}

		vector<int> dp(amount + 1);
		int size = coins.size();

		for (int i = 1; i <= amount; i++)
		{
			dp[i] = -1;
			for (int j = 0; j < size; j++)
			{
				if (coins[j] <= i)
				{
					if (dp[i - coins[j]] < 0) continue;

					if (dp[i] < 0)
					{
						dp[i] = dp[i - coins[j]] + 1;
					}
					else if (dp[i - coins[j]] + 1 < dp[i])
					{
						dp[i] = dp[i - coins[j]] + 1;
					}
				}
			}
		}
		return dp[amount];
	}
};