class Solution {
public:
    int rob(vector<int>& nums) {
        int ans = 0;
        int dp[2][1001];

        for(int i=0; i<2; i++) fill(dp[i], dp[i]+1001, -1);
        dp[0][0] = dp[1][0] = 0;
        dp[0][1] = nums[0];
        dp[1][1] = 0;
        ans = max(dp[0][1], dp[1][1]);

        for(int i=1; i<nums.size(); i++) {
            // 0
            if(i <nums.size()-1)
                dp[0][i+1] = max(dp[0][i], dp[0][i-1]+nums[i]);

            // 1
            dp[1][i+1] = max(dp[1][i], dp[1][i-1]+nums[i]);

            ans = max(ans, max(dp[0][i+1], dp[1][i+1]));
        }

        // for(int i=0; i<=nums.size(); i++) {
        //     cout << dp[0][i] << ' ';
        // }
        // cout << endl;
        // for(int i=0; i<=nums.size(); i++) {
        //     cout << dp[1][i] << ' ';
        // }
        // cout << endl;
        return ans;
    }
};