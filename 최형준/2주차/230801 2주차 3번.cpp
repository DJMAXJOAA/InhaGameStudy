class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int iMax = 0;
        int iMin = prices[0];
        for (int i = 1; i < prices.size(); i++)
        {
            iMin = min(iMin, prices[i]);
            iMax = max(iMax, prices[i] - iMin);
        }

        return iMax;
    }
};