// https://leetcode.com/problems/counting-bits/

class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> dp(100001, -1);
        vector<int> ans;

        dp[0] = 0;
        dp[1] = 1;
        int num = 2;

        while(num <= n)
        {
            for(int i = num; i < num * 2; i++)
            {
                if(i > n) break;
                dp[i] = 1 + dp[i-num];
            }

            num *= 2;
        }        

        for(int i=0; i<=n; i++)
        {
            ans.push_back(dp[i]);
        }

        return ans;
    }
};
