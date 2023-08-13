class Solution
{
    //int table[10001] = {}; //aproach DP 

public:
    int coinChange(vector<int>& coins, int amount)
    {
        unsigned int dp[amount + 1];
        fill(dp, dp + amount + 1, INT_MAX); //dp array initalize INT_MAX
        dp[0] = 0;
        for (int i = 1; i <= amount; i++)
        {
            for (int j = 0; j < coins.size(); j++)
            {
                if (coins[j] <= i) //should big
                {
                    dp[i] = min(dp[i], dp[i - coins[j]] + 1);//INT_MAX is useful
                }
            }
        }

        if (dp[amount] == INT_MAX) return -1;
        else return dp[amount];

    }
    // int coinChange(vector<int>& coins, int amount)
    // {

    //     if(amount==0) return 0;
    //     int n = coins.size();

    //     for(int i = 0; i<n;i++)
    //     {
    //         if(coins[i]<10001)
    //         {
    //             table[coins[i]]=1;
    //         }
    //     }

    //     for(int i = 0;i<=amount;i++)
    //     {
    //         int min = 10001;
    //         for(int j = 0; j<n;j++)
    //         {
    //             if(i-coins[j] < 0) continue;
    //             table[i]= (min < table[i-coins[j]]+1) ? min:table[i-coins[j]]+1; //want fewest number
    //         }
    //     }

    //     if(table[amount]==0) return -1;
    //     return table[amount];
    // }

};