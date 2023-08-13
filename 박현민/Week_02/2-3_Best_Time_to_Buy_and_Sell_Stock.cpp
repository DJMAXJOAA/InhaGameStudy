class Solution {
public:
    int maxProfit(vector<int>& prices) {
        vector<bool> closed(10001, false);
        int profit = 0;
        int max = FindMax(prices, 0);
        int size = prices.size();

        for (int i = 0; i < size - 1; i++)
        {
            if (closed[prices[i]])
                continue;            

            closed[prices[i]] = true;
            
            if (max < i)
                max = FindMax(prices, i);

            if (prices[max] - prices[i] > profit)
                profit = prices[max] - prices[i];
        }

        return profit;
    }

    int FindMax(vector<int>& prices, int start)
    {
        int max = start;
        for (int i = start; i < prices.size(); i++)
        {
            if (prices[max] < prices[i])
                max = i;
        }
        return max;
    }
};