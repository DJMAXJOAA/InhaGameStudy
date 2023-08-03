// https://leetcode.com/problems/best-time-to-buy-and-sell-stock/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // 7 1 5 3 6 4
        stack<int> S;

        int ans = 0;

        for(int i=0; i<prices.size(); i++)
        {
            int cur = prices[i];
            if(S.empty()) 
            {
                S.push(cur);
                continue;
            }

            if(S.top() >= cur)
            {
                while(!S.empty() && S.top() >= cur)
                {
                    S.pop();
                }
                S.push(cur);
            }
            else
            {
                ans = max(ans, cur - S.top());
            }
        }

        return ans;

    }
};