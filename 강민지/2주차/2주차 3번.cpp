class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        int min = prices[0];
        int max = 0;
        int answer = 0;

        for(int i = 1; i < prices.size(); i++)
        {
            if(min > prices[i]) 
                min = prices[i];
            else
            {
                max = prices[i] - min;
                if(answer < max)    
                    answer = max;
            }
        }

        return answer;
    }
};
