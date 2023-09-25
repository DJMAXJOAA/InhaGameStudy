class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int dp[100005];
        fill(dp, dp+100005, 0);

        for(int i=0; i< nums.size(); i++) {
            dp[i+1] = max(nums[i], dp[i]+nums[i]);
        }

        return *max_element(dp+1, dp+nums.size()+1);
    }
};